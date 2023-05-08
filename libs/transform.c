

# include <SDL2/SDL.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_render.h>
# include <SDL2/SDL_surface.h>
# include <math.h>
# include <stdio.h>

# include "../cpygame.h"


SDL_Point transform_rotated_size (SDL_Texture *texture, int angle) {

	SDL_Point original_size;
	SDL_Point new_size;
	SDL_QueryTexture(texture, NULL, NULL, &original_size.x, &original_size.y);

	int w = original_size.x;
	int h = original_size.y;

	int maxX = 0;
	int maxY = 0;

	SDL_Point center = {
		.x = w / 2,
		.y = h / 2
	};

	for (int i = 0; i < arrlen(ROTATIONS); i++) {
		// calc the distance
		int c[] = {center.x, center.y};
		int p[] = {ROTATIONS[i][0] * w, ROTATIONS[i][1] * h};
		float distance = dist(p, c);

		// calc point angle after rotation
		double new_angle = (double)angle / 180 * pi;
		double start_angle = atan2(ROTATIONS[i][1] * h - center.y, ROTATIONS[i][0] * w - center.x);
		double final_angle = new_angle + start_angle;

		// calc new point
		int dx = center.x + cos(final_angle) * distance;
		int dy = center.y + sin(final_angle) * distance;
		
		// set new max
		if (maxX < abs(dx)) maxX = dx;
		if (maxY < abs(dy)) maxY = dy;
	}
	new_size.x = maxX;
	new_size.y = maxY;

	return new_size;
}

SDL_Texture* transform_rotate (SDL_Texture *texture, int angle) {
	SDL_Point new_size = transform_rotated_size(texture, angle);
	int w = new_size.x;
	int h = new_size.y;


	// create transparent surface
	SDL_Surface *surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGBA(surface->format, 255, 0, 255, 0));
	SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 255, 0, 255, 0));
	/* SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 255, 0, 0, 0)); */


	// create new texture
	SDL_Texture *new_texture = SDL_CreateTexture(cpg.window.renderer, surface->format->format, SDL_TEXTUREACCESS_TARGET, w, h);

	// paste surface pixeldata to new_texture
	SDL_UpdateTexture(new_texture, NULL, surface->pixels, surface->pitch);

	// set render target to new texture
	SDL_SetRenderTarget(cpg.window.renderer, new_texture);

	// blit rotated texture
	window_blit_rot(texture, TOPLEFT, angle);

	// set target back to window
	SDL_SetRenderTarget(cpg.window.renderer, NULL);

	return new_texture;
}

