#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

float rotate_x=0;
float rotate_y=0;

SDL_Window *window;
SDL_Event event;

const Uint8 *key=SDL_GetKeyboardState(0);

int main(){
    window=SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_OPENGL);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GLContext context=SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(SDL_FALSE);

    while(window!=NULL){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT)
                window=NULL;
            if(event.key.keysym.scancode==SDL_SCANCODE_ESCAPE)
                window=NULL;
        }

        if(key[SDL_SCANCODE_D])
            rotate_y-=0.04;
        if(key[SDL_SCANCODE_A])
            rotate_y+=0.04;
        if(key[SDL_SCANCODE_W])
            rotate_x+=0.04;
        if(key[SDL_SCANCODE_S])
            rotate_x-=0.04;

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glPushMatrix();
        glEnable(GL_DEPTH_TEST);

        glRotatef( rotate_x, 1.0, 0.0, 0.0 );
        glRotatef( rotate_y, 0.0, 1.0, 0.0 );

        glBegin(GL_POLYGON);
            glColor3f( 1.0, 0.0, 0.0 ); glVertex3f(  0.5, -0.5, -0.5 );
            glColor3f( 0.0, 1.0, 0.0 ); glVertex3f(  0.5,  0.5, -0.5 );
            glColor3f( 0.0, 0.0, 1.0 ); glVertex3f( -0.5,  0.5, -0.5 );
            glColor3f( 1.0, 0.0, 1.0 ); glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(   1.0,  1.0, 1.0 );
            glVertex3f(  0.5, -0.5, 0.5 );
            glVertex3f(  0.5,  0.5, 0.5 );
            glVertex3f( -0.5,  0.5, 0.5 );
            glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(  1.0,  0.0,  1.0 );
            glVertex3f( 0.5, -0.5, -0.5 );
            glVertex3f( 0.5,  0.5, -0.5 );
            glVertex3f( 0.5,  0.5,  0.5 );
            glVertex3f( 0.5, -0.5,  0.5 );
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(   0.0,  1.0,  0.0 );
            glVertex3f( -0.5, -0.5,  0.5 );
            glVertex3f( -0.5,  0.5,  0.5 );
            glVertex3f( -0.5,  0.5, -0.5 );
            glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(   0.0,  0.0,  1.0 );
            glVertex3f(  0.5,  0.5,  0.5 );
            glVertex3f(  0.5,  0.5, -0.5 );
            glVertex3f( -0.5,  0.5, -0.5 );
            glVertex3f( -0.5,  0.5,  0.5 );
        glEnd();

        glBegin(GL_POLYGON);
            glColor3f(   1.0,  0.0,  0.0 );
            glVertex3f(  0.5, -0.5, -0.5 );
            glVertex3f(  0.5, -0.5,  0.5 );
            glVertex3f( -0.5, -0.5,  0.5 );
            glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();
        
        glDisable(GL_DEPTH_TEST);
        glPopMatrix();

        SDL_GL_SwapWindow(window);
    }
}
