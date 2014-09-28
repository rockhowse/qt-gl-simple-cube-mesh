// code taken from:
// http://sorj.de/?p=192
#include "myglwidget.h"
#include "Block.h"

/*
 * Sets up the OpenGL rendering context, defines display lists, etc.
 * Gets called once before the first time resizeGL() or paintGL() is called.
 */
void MyGLWidget::initializeGL(){
    //activate the depth buffer
    glEnable(GL_DEPTH_TEST);
}


/*
 *  Sets up the OpenGL viewport, projection, etc. Gets called whenever the widget has been resized
 *  (and also when it is shown for the first time because all newly created widgets get a resize event automatically).
 */
void MyGLWidget::resizeGL (int width, int height){
    glViewport( 0, 0, (GLint)width, (GLint)height );

    /* create viewing cone with near and far clipping planes */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 500.0);

    glMatrixMode( GL_MODELVIEW );
}

/*
 * Renders the OpenGL scene. Gets called whenever the widget needs to be updated.
 */
void MyGLWidget::paintGL(){

    //delete color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    float blockSize = Block::BLOCK_SIZE;
    float block_cube_size = 10.0;
    float translate_distance = (block_cube_size*block_cube_size+20)*-1;

    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,-200.0f); //move along z-axis
        glRotatef(45.0,0.0,1.0,0.0); //rotate 30 degress around y-axis
        glRotatef(45.0,0.0,0.0,1.0); //rotate 15 degress around x-axis

    float x = 0.0;
    float y = 0.0;
    float z = 0.0;

    for(x = 0.0; x < block_cube_size; x += blockSize)
    {
        for(y = 0.0; y < block_cube_size; y += blockSize)
        {
            for(z = 0.0; z < block_cube_size; z += blockSize)
            {
                glPushMatrix();
                    glTranslatef(x, y, z);

                    // Turn on wireframe mode
                    // http://stackoverflow.com/questions/137629/how-do-you-render-primitives-as-wireframes-in-opengl
                    glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);

                    /* create 3D-Cube */
                    glBegin(GL_QUADS);

                        //front
                        //glColor3f(1.0,0.0,0.0);

                        glVertex3f(1.0,1.0,1.0);
                        glVertex3f(-1.0,1.0,1.0);
                        glVertex3f(-1.0,-1.0,1.0);
                        glVertex3f(1.0,-1.0,1.0);


                        //back

                        //glColor3f(0.0,1.0,0.0);

                        glVertex3f(1.0,1.0,-1.0);
                        glVertex3f(-1.0,1.0,-1.0);
                        glVertex3f(-1.0,-1.0,-1.0);
                        glVertex3f(1.0,-1.0,-1.0);


                        //top
                        //glColor3f(0.0,0.0,1.0);

                        glVertex3f(-1.0,1.0,1.0);
                        glVertex3f(1.0,1.0,1.0);
                        glVertex3f(1.0,1.0,-1.0);
                        glVertex3f(-1.0,1.0,-1.0);


                        //bottom
                        //glColor3f(0.0,1.0,1.0);

                        glVertex3f(1.0,-1.0,1.0);
                        glVertex3f(1.0,-1.0,-1.0);
                        glVertex3f(-1.0,-1.0,-1.0);
                        glVertex3f(-1.0,-1.0,1.0);

                        //right
                        //glColor3f(1.0,0.0,1.0);

                        glVertex3f(1.0,1.0,1.0);
                        glVertex3f(1.0,-1.0,1.0);
                        glVertex3f(1.0,-1.0,-1.0);
                        glVertex3f(1.0,1.0,-1.0);


                        //left
                        //glColor3f(1.0,1.0,0.0);

                        glVertex3f(-1.0,1.0,1.0);
                        glVertex3f(-1.0,-1.0,1.0);
                        glVertex3f(-1.0,-1.0,-1.0);
                        glVertex3f(-1.0,1.0,-1.0);
                    glEnd();

                    // Turn off wireframe mode
                    glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);
               glPopMatrix();
            }
        }
    }
}
