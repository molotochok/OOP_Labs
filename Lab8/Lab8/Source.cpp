#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>

void cylinder()
{
	const double PI = 3.14159;

	/* top triangle */
	double i, resolution = 0.1;
	double height = 1;
	double radius = 0.5;

	glPushMatrix();
	glTranslatef(0, -0.5, 0);

	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0, height, 0);  /* center */
	for (i = 2 * PI; i >= 0; i -= resolution)

	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	/* close the loop back to 0 degrees */
	glTexCoord2f(0.5, 0.5);
	glVertex3f(radius, height, 0);
	glEnd();

	/* bottom triangle: note: for is in reverse order */
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0, 0, 0);  /* center */
	for (i = 0; i <= 2 * PI; i += resolution)
	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * cos(i), 0, radius * sin(i));
	}
	glEnd();

	/* middle tube */
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= 2 * PI; i += resolution)
	{
		const float tc = (i / (float)(2 * PI));
		glTexCoord2f(tc, 0.0);
		glVertex3f(radius * cos(i), 0, radius * sin(i));
		glTexCoord2f(tc, 1.0);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	/* close the loop back to zero degrees */
	glTexCoord2f(0.0, 0.0);
	glVertex3f(radius, 0, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(radius, height, 0);
	glEnd();

	glPopMatrix();
}

GLuint tex;
void init()
{
	unsigned char data[] =
	{
		512, 124, 34, 21,
		255, 255, 11, 34,
		123, 255, 123, 15,
		12, 44, 255, 23,
	};

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

float angle = 0;
void timer(int value)
{
	angle += 1;
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(32, 1.0, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -5);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glRotatef(angle, 0.0f, angle, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	cylinder();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("GLUT");

	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}