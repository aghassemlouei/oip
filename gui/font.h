
#ifndef FONT_H
#define FONT_H

#include <ft2build.h>
#include FT_FREETYPE_H

#include <SDL/SDL.h>
#include <string>
using std::string;


namespace gui
{

	class font
	{
	private:
		void ref(bool addref);
		FT_Face face;
		bool valid;
		int fontsize;
		int error;
		void draw_glyph(int x, int y, FT_Bitmap* bmp, SDL_Surface* s);
		Uint32 color;
	public:
		font(const char* path="Vera.ttf", int size=24);
		~font();

		void render(const string& s, int x, int y, SDL_Surface* surf);
		void render(const char* s, int x, int y, SDL_Surface* surf) {render(string(s),x,y,surf);}
		
		bool isValid() { return !error; }
		int getError() { return error; }
		void setSize(int size); 
		int getSize() { return fontsize; }
		void getSize(const string& s, int& w, int & h);
		void getSize(const char* s, int&w, int&h) {getSize(string(s), w, h);}
		Uint32 getColor() {return color;}
		void setColor(Uint32 c) {color = c;}
	};
};

#endif//FONT_H

