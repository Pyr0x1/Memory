#include <iostream>
#include <sstream>
#include "Score.h"

Score::Score (std::string fontPath, SDL_Color fontColor, int size) {

	this->font = TTF_OpenFont (fontPath.c_str(), size);
	if(!this->font)
		printf("TTF_OpenFont: %s\n", TTF_GetError());

	this->color = fontColor;
	this->value = 0;
}

void Score::write (SDL_Renderer* renderer, SDL_Point position) {

	std::ostringstream oStream;
	oStream << this->value;
	std::string valueStr = oStream.str ();

	this->surface = TTF_RenderText_Solid (this->font, valueStr.c_str (), this->color);
	this->texture = SDL_CreateTextureFromSurface (renderer, this->surface);

	SDL_Rect destRect = {position.x, position.y, this->surface->w, this->surface->h};
	SDL_RenderCopy (renderer, this->texture, NULL, &destRect);

	SDL_FreeSurface (this->surface);

	return ;
}

void Score::increase () {

	this->value++;
}

void Score::reset () {

	this->value = 0;
}

Score::~Score () {

	TTF_CloseFont (this->font);
	SDL_DestroyTexture (this->texture);
}

