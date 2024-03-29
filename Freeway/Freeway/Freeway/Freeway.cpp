// Freeway.cpp : define o ponto de entrada para o aplicativo do console.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

#define janela_altura 400
#define janela_largura 600

void display(void);
void tela(GLsizei w, GLsizei h);

int velocidade1 = -380;
int velocidade2 = -380;
int velocidade3 = -380;
int velocidade4 = 380;
int velocidade5 = 380;
int velocidade6 = 380;

int gy1 = -180;
int gx1 = -150;
int gx2 = 150;
int gy2 = -180;


//galinha tamanho
int ga1 = 25;
int gl1 = 25;

int ga2 = 25;
int gl2 = 25;

int velocidade = 0;

//carro1
int largura1 = 80;
int altura1 = 40;
int carroy1 = -145;
//carro2
int largura2 = 80;
int altura2 = 40;
int carroy2 = -95;
//carro3
int largura3 = 80;
int altura3 = 40;
int carroy3 = -45;
//carro4
int largura4 = 80;
int altura4 = 40;
int carroy4 = 5;
//carro5
int largura5 = 80;
int altura5 = 40;
int carroy5 = 55;
//carro6
int largura6 = 80;
int altura6 = 40;
int carroy6 = 105;



void controle(unsigned char tecla, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv); //suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//padrao de cores

	glutInitWindowSize(janela_largura, janela_altura); //tamanho da janela
	glutInitWindowPosition(100, 100); // posição da tela
	glutCreateWindow("FreeWay"); //cria janela

	glutReshapeFunc(tela); // configura a tela
	glutKeyboardFunc(&controle);
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}

void controle(unsigned char tecla, int a, int b) {

	if (GetAsyncKeyState('W')) gy1 += 5;
	if (GetAsyncKeyState('S')) gy1 -= 5;

	if (GetAsyncKeyState('I')) gy2 += 5;
	if (GetAsyncKeyState('K')) gy2 -= 5;


	glutPostRedisplay();


}

// cenario a rua e as calçadas
void ambiente() {


	glPushMatrix();
	//rua
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(-300, 150);
	glVertex2f(300, 150);
	glVertex2f(300, -150);
	glVertex2f(-300, -150);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3, 3);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(-300, -100);
	glVertex2f(300, -100);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3, 3);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(-300, -50);
	glVertex2f(300, -50);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3, 3);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(-300, 0);
	glVertex2f(300, 0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3, 3);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(-300, 50);
	glVertex2f(300, 50);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3, 3);
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(-300, 100);
	glVertex2f(300, 100);
	glEnd();

	glPopMatrix();

	//calçadas
	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0, 0.2, 0);
	glVertex2f(-300, -150);
	glVertex2f(300, -150);
	glVertex2f(300, -200);
	glVertex2f(-300, -200);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glBegin(GL_QUADS);
	glColor3f(0, 0.2, 0);
	glVertex2f(-300, 150);
	glVertex2f(300, 150);
	glVertex2f(300, 200);
	glVertex2f(-300, 200);
	glEnd();

	glPopMatrix();
	/*
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(0, 0);
	glVertex2f(50, 0);
	glVertex2f(50, -50);
	glVertex2f(0, -50);
	glEnd();
	*/
}

void carro1() {


	glPushMatrix();
	glTranslatef(velocidade1, carroy1, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex2f(0, altura1);
	glVertex2f(largura1, altura1);
	glVertex2f(largura1, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(20, 5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(30, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();


	glPopMatrix();

}

void carro2() {


	glPushMatrix();
	glTranslatef(velocidade2, carroy2, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(0, altura2);
	glVertex2f(largura2, altura2);
	glVertex2f(largura2, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(20, 5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(30, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();


	glPopMatrix();

}

void carro3() {


	glPushMatrix();
	glTranslatef(velocidade3, carroy3, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 1, 1);
	glVertex2f(0, altura3);
	glVertex2f(largura3, altura3);
	glVertex2f(largura3, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(20, 5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(30, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();


	glPopMatrix();

}

void carro4() {


	glPushMatrix();
	glTranslatef(velocidade4, carroy4, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(0, altura4);
	glVertex2f(largura4, altura4);
	glVertex2f(largura4, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(20, 5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(30, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();


	glPopMatrix();

}


void carro5() {


	glPushMatrix();
	glTranslatef(velocidade5, carroy5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex2f(0, altura5);
	glVertex2f(largura5, altura5);
	glVertex2f(largura5, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(20, 5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(30, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();


	glPopMatrix();

}

void carro6() {


	glPushMatrix();
	glTranslatef(velocidade6, carroy6, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(0, altura6);
	glVertex2f(largura6, altura6);
	glVertex2f(largura6, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(20, 5, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();

	glTranslatef(30, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(0, 30);
	glVertex2f(10, 30);
	glVertex2f(10, 0);
	glVertex2f(0, 0);
	glEnd();


	glPopMatrix();

}

void galinha1() {
	glPushMatrix();
	glTranslatef(gx1, gy1, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0.2, 0,0);
	glBegin(GL_QUADS);
	glVertex2f(0, ga1);
	glVertex2f(gl1, ga1);
	glVertex2f(gl1, 0);
	glVertex2f(0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(5,23);
	glVertex2f(20,23);
	glVertex2f(20,3);
	glVertex2f(5,3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(0, 3);
	glVertex2f(15, 3);
	glVertex2f(15, 0);
	glVertex2f(0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glVertex2f(0,18);
	glVertex2f(5,20);
	glVertex2f(5,16);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(10,18);
	glVertex2f(14,18);
	glVertex2f(14,16);
	glVertex2f(10,16);
	glEnd();
	glPopMatrix();
}

void galinha2() {
	glPushMatrix();
	glTranslatef(gx2, gy2, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0, 0.2, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(0, ga2);
	glVertex2f(gl2, ga2);
	glVertex2f(gl2, 0);
	glVertex2f(0, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(5, 23);
	glVertex2f(20, 23);
	glVertex2f(20, 3);
	glVertex2f(5, 3);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex2f(0, 3);
	glVertex2f(15, 3);
	glVertex2f(15, 0);
	glVertex2f(0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 0);
	glVertex2f(0, 18);
	glVertex2f(5, 20);
	glVertex2f(5, 16);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(10, 18);
	glVertex2f(14, 18);
	glVertex2f(14, 16);
	glVertex2f(10, 16);
	glEnd();

	glPopMatrix();
}

void jogo() {
	srand(time(NULL));
	velocidade = rand() % 3;
	velocidade1 += velocidade;
	if (velocidade1 > 380) {
		velocidade1 = -380;
	}
	velocidade = rand() % 3;
	velocidade2 += velocidade;
	if (velocidade2 > 380) {
		velocidade2 = -380;
	}
	velocidade = rand() % 3;
	velocidade3 += velocidade;
	if (velocidade3 > 300) {
		velocidade3 = -380;
	}
	velocidade = rand() % 3;
	velocidade4 -= velocidade;
	if (velocidade4 < -380) {
		velocidade4 = 380;
	}
	velocidade = rand() % 3;
	velocidade5 -= velocidade;
	if (velocidade5 < -380) {
		velocidade5 = 380;
	}
	velocidade = rand() % 3;
	velocidade6 -= velocidade;
	if (velocidade6 < -380) {
		velocidade6 = 380;
	}

	if (gy1 > 175) {
		gy1 = -180;
	}

	if (gy2 > 175) {
		gy2 = -180;
	}
	// colisao 1
	if ((gx1+gl1 >= velocidade1 && gx1+gl1 <= velocidade1 + largura1 && gy1 >= carroy1 && gy1 <= carroy1 + altura1)||(gy1 + ga1 >= carroy1 && gy1 + ga1 <= carroy1 + altura1) && (gx1 + gl1 >= velocidade1 && gx1 + gl1 <= velocidade1 + largura1)){
		gy1 = -180;
	}

	if ((gx2 + gl2 >= velocidade1 && gx2 + gl2 <= velocidade1 + largura1 && gy2 >= carroy1 && gy2 <= carroy1 + altura1) || (gy2 + ga2 >= carroy1 && gy2 + ga2 <= carroy1 + altura1) && (gx2 + gl2 >= velocidade1 && gx2 + gl2 <= velocidade1 + largura1)) {
		gy2 = -180;
	}
	// colisao 2
	if ((gx1 + gl1 >= velocidade2 && gx1 + gl1 <= velocidade2 + largura2 && gy1 >= carroy2 && gy1 <= carroy2 + altura2) || (gy1 + ga1 >= carroy2 && gy1 + ga1 <= carroy2 + altura2) && (gx1 + gl1 >= velocidade2 && gx1 + gl1 <= velocidade2 + largura2)) {
		gy1 = -180;
	}

	if ((gx2 + gl2 >= velocidade2 && gx2 + gl2 <= velocidade2 + largura2 && gy2 >= carroy2 && gy2 <= carroy2 + altura2) || (gy2 + ga2 >= carroy2 && gy2 + ga2 <= carroy2 + altura2) && (gx2 + gl2 >= velocidade2 && gx2 + gl2 <= velocidade2 + largura2)) {
		gy2 = -180;
	}

	// colisao 3
	if ((gx1 + gl1 >= velocidade3 && gx1 + gl1 <= velocidade3 + largura3 && gy1 >= carroy3 && gy1 <= carroy3 + altura3) || (gy1 + ga1 >= carroy3 && gy1 + ga1 <= carroy3 + altura3) && (gx1 + gl1 >= velocidade3 && gx1 + gl1 <= velocidade3 + largura3)) {
		gy1 = -180;
	}

	if ((gx2 + gl2 >= velocidade3 && gx2 + gl2 <= velocidade3 + largura3 && gy2 >= carroy3 && gy2 <= carroy3 + altura3) || (gy2 + ga2 >= carroy3 && gy2 + ga2 <= carroy3 + altura3) && (gx2 + gl2 >= velocidade3 && gx2 + gl2 <= velocidade3 + largura3)) {
		gy2 = -180;
	}

	// colisao 4
	if ((gx1 + gl1 >= velocidade4 && gx1 + gl1 <= velocidade4 + largura4 && gy1 >= carroy4 && gy1 <= carroy4 + altura4) || (gy1 + ga1 >= carroy4 && gy1 + ga1 <= carroy4 + altura4) && (gx1 + gl1 >= velocidade4 && gx1 + gl1 <= velocidade4 + largura4)) {
		gy1 = -180;
	}

	if ((gx2 + gl2 >= velocidade4 && gx2 + gl2 <= velocidade4 + largura4 && gy2 >= carroy4 && gy2 <= carroy4 + altura4) || (gy2 + ga2 >= carroy4 && gy2 + ga2 <= carroy4 + altura4) && (gx2 + gl2 >= velocidade4 && gx2 + gl2 <= velocidade4 + largura4)) {
		gy2 = -180;
	}

	// colisao 5
	if ((gx1 + gl1 >= velocidade5 && gx1 + gl1 <= velocidade5 + largura5 && gy1 >= carroy5 && gy1 <= carroy5 + altura5) || (gy1 + ga1 >= carroy5 && gy1 + ga1 <= carroy5 + altura5) && (gx1 + gl1 >= velocidade5 && gx1 + gl1 <= velocidade5 + largura5)) {
		gy1 = -180;
	}

	if ((gx2 + gl2 >= velocidade5 && gx2 + gl2 <= velocidade5 + largura5 && gy2 >= carroy5 && gy2 <= carroy5 + altura5) || (gy2 + ga2 >= carroy5 && gy2 + ga2 <= carroy5 + altura5) && (gx2 + gl2 >= velocidade5 && gx2 + gl2 <= velocidade5 + largura5)) {
		gy2 = -180;
	}
	// colisao 6
	if ((gx1 + gl1 >= velocidade6 && gx1 + gl1 <= velocidade6 + largura6 && gy1 >= carroy6 && gy1 <= carroy6 + altura6) || (gy1 + ga1 >= carroy6 && gy1 + ga1 <= carroy6 + altura6) && (gx1 + gl1 >= velocidade6 && gx1 + gl1 <= velocidade6 + largura6)) {
		gy1 = -180;
	}

	if ((gx2 + gl2 >= velocidade6 && gx2 + gl2 <= velocidade6 + largura1 && gy2 >= carroy6 && gy2 <= carroy6 + altura6) || (gy2 + ga2 >= carroy6 && gy2 + ga2 <= carroy6 + altura6) && (gx2 + gl2 >= velocidade6 && gx2 + gl2 <= velocidade6 + largura6)) {
		gy2 = -180;
	}

	glutPostRedisplay();
}

void display() {
	glMatrixMode(GL_MODELVIEW); // coordenadas de desenho
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT); //executa limpeza

								  //espefica onde o desenho vai aparecer
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);
	glViewport(0, 0, janela_largura, janela_altura);
	ambiente();
	carro1();
	carro2();
	carro3();
	carro4();
	carro5();
	carro6();
	galinha1();
	galinha2();
	jogo();

	glFlush(); // execute o desenho

}

void tela(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//cria a janela
	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);
}





