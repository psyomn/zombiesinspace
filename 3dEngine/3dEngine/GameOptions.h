/**
  @author George Gonis
  @date June 19,2010
  @section DESCRIPTION
  
  Keeps all information from user about the window being created.
*/


#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

class  GameOptions{

private:
  int width;
  int height;
  int bpp;
  bool fullscreen;

public:
  GameOptions();                    // Default values (Constructor)
  ~GameOptions();                   // Cleans class when exiting (Destructor)
  void SetWidth(const int w);       // Sets the width of the window.
  void SetHeight(const int h);      // Set the height of the window.
//  void SetFullscreen(const bool f);  // Sets the window to fullscreen or windowed mode.
//  void SelectScreen();             // Gets the mode for the screen (windowed or fullscreen)
  void SelectResolution();          // User selects resolution to apply to window
  void SetGameOptions();            // Main function that calls all others within this class   <-- START HERE
  void SelectBitsPerPixel();        // Selects the Bits per pixel
  void SetBpp(const int b);         // Sets the bits per pixel
  const int GetBpp();              // Gets the bits per pixel
  const int GetWidth();            // Gets the width of the window
  const int GetHeight();            // Gets the height of the window
//  const bool GetFullscreen();
};

// Default values (Constructor)
GameOptions::GameOptions() 
  :  width(640),  height(480),  fullscreen(false)
{
  // Empty body
}

// Cleans class when exiting (Destructor)
GameOptions::~GameOptions() {
  // Empty body
}

// Sets the width of the window.
void GameOptions::SetWidth(const int w) {
  width = w;
}

// Set the height of the window.
void GameOptions::SetHeight(const int h) {
  height = h;
}

/*
// Sets the window to fullscreen or windowed mode.
void GameOptions::SetFullscreen(const bool f) {
  fullscreen = f;
}
*/

// Gets the width of the window
const int GameOptions::GetWidth() {
  return width;
}

// Gets the height of the window
const int GameOptions::GetHeight() {
  return height;
}

// Sets the bits per pixel
void GameOptions::SetBpp(const int b) {
  bpp = b;
}

// Gets the bits per pixel
const int GameOptions::GetBpp() {
  return bpp;
}

/*
// Gets the mode for the screen (windowed or fullscreen)
const bool GameOptions::GetFullscreen() {
  return fullscreen;
}
*/

// User selects resolution to apply to window
void GameOptions::SelectResolution() {
  int res;

  printf("Select a resolution: \n");
  printf(" 1) 640x480\n");
  printf(" 2) 800x600\n");
  printf(" 3) 1024x786\n");
  printf(" 4) 1280x720 (Widescreen)\n");
  printf(" 5) 1280x1024\n\n");
  scanf("%1d", &res);

  switch(res)
  {
    case 5: SetWidth(1280);
        SetHeight(1024);
        break;
    case 4: SetWidth(1280);
        SetHeight(720);
        break;
    case 3: SetWidth(1024);
        SetHeight(786);
        break;
    case 2: SetWidth(800);
        SetHeight(600);
        break;
    default: SetWidth(640);
        SetHeight(480);
        break;
  }
  printf("\n\n");
}

// Selects the Bits per pixel
void GameOptions::SelectBitsPerPixel() {
  int bpp;

  printf("Select the Bits per Pixel: \n");
  printf(" 1) 8\n");
  printf(" 2) 16\n");
  printf(" 3) 32\n");
  scanf("%1d", &bpp);

  switch(bpp)
  {
    case 3: SetBpp(32);
        break;
    case 2: SetBpp(16);
        break;
    default: SetBpp(8);
        break;
  }
  printf("\n\n");
}

/*
// Selects windowed or fullscreen mode
void GameOptions::SelectScreen() {
  int x;

  printf("Windowed or Fullscreen? \n");
  printf(" 1) Windowed\n");
  printf(" 2) Fullscreen\n");
  scanf("%1d", &x);

  switch(bpp)
  {
    case 2: SetFullscreen(true);
        break;
    default: SetFullscreen(false);
        break;
  }
  printf("\n\n");
}
*/

// Main function that calls all others within this class
void GameOptions::SetGameOptions() {
  SelectResolution();
  SelectBitsPerPixel();
//  SelectScreen();
}

#endif


