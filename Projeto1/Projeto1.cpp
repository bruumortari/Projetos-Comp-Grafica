//*****************************************************
// Bruna Bertolo Mortari 11795892
// Sabrina Kappann da Silva 11208332
// 
// Este projeto cria um robô 3D iluminado pelo sol (durante o dia) e pela lua (durante a noite).
// Durante a noite, estrelas aparecem no céu e os olhos do robô acendem.
// Para alternar entre dia e noite, é necessário clicar com os botões do mouse:
//        BOTÃO ESQUERDO - NOITE
//		  BOTÃO DIREITO - DIA
// Quando está de noite, ou seja, o botão esquerdo do mouse já tover sido clicado, pode-se clicar continuamente com ele para as estrelas girarem.
//		  FICAR CLICANDO COM O BOTÃO ESQUERDO - ESTRELAS GIRAM
// Também é possível aumentar o robô de tamanho usando as setas do teclado:
//        UP KEY seguido de CLICAR COM QUALQUER BOTÃO DO MOUSE - ROBÔ AUMENTA DE TAMANHO E REDESENHA A CENA
//        DOWN KEY seguido de CLICAR COM QUALQUER BOTÃO DO MOUSE - ROBÔ VOLTA AO TAMANHO ORIGINAL E REDESENHA A CENA
//*****************************************************
#include <GL/glut.h>
#include <iostream>
#include <math.h>
GLfloat angle, fAspect, largura, altura, ycamera;
GLdouble Px, Py, Pz;
float xc = 0, yc = 0, zc = 300, xa = 0, ya = 0, za = 0, xo = 0, yo = 1, zo = 0;
float r = 1.0f, g = 1.0f, b = 0.0f, radius = 15.0, Rsol = 1.0f, Gsol = 1.0f, Bsol = 1.0f;
double dx = 0, dy = 0, Erobo = 1.0;
int angulo = 0;
bool isNight = true;

// Função para desenhar o chão
void DesenhaChao()
{	
	glBegin(GL_POLYGON);
		glColor3f(0.1f, 1.0f, 0.4f);
		glVertex2f(-300.0, -90.0);
		glVertex2f(300.0, -90.0);
		glVertex2f(300.0, -300.0);
		glVertex2f(-300.0, -300.0);
	glEnd();
}

void DesenhaAntenaRobo()
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(0.0, 70.0);
		glVertex2f(0.0, 10.0);
	glEnd();		
}

void DesenhaEsferaRobo()
{
	glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(3, 100, 100);
	glPopMatrix();
}

// Função para desenhar todas as estrelas
void DesenhaEstrela1()
{
	//Estrela 1
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(25.0, 30.0);
		glVertex2f(40.0, 40.0);
		glVertex2f(30.0, 25.0);
		glVertex2f(40.0, 10.0);
		glVertex2f(25.0, 20.0);
		glVertex2f(10.0, 10.0);
		glVertex2f(20.0, 25.0);
		glVertex2f(10.0, 40.0);
	glEnd();
}

void DesenhaEstrela2()
{
	//Estrela 2
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(50.0, 20.0);
		glVertex2f(80.0, 40.0);
		glVertex2f(60.0, 10.0);
		glVertex2f(80.0, -20.0);
		glVertex2f(50.0, 0.0);
		glVertex2f(20.0, -20.0);
		glVertex2f(40.0, 10.0);
		glVertex2f(20.0, 40.0);
	glEnd();
}

void DesenhaEstrela3()
{
	//Estrela 3
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(25.0, 0.0);
		glVertex2f(40.0, 10.0);
		glVertex2f(30.0, -5.0);
		glVertex2f(40.0, -20.0);
		glVertex2f(25.0, -10.0);
		glVertex2f(10.0, -20.0);
		glVertex2f(20.0, -5.0);
		glVertex2f(10.0, 10.0);
	glEnd();
}

void DesenhaEstrela4()
{
	//Estrela 4
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-35.0, 0.0);
		glVertex2f(-20.0, 10.0);
		glVertex2f(-30.0, -5.0);
		glVertex2f(-20.0, -20.0);
		glVertex2f(-35.0, -10.0);
		glVertex2f(-50.0, -20.0);
		glVertex2f(-40.0, -5.0);
		glVertex2f(-50.0, 10.0);
	glEnd();
}

void DesenhaEstrela5()
{
	//Estrela 5
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-20.0, 30.0);
		glVertex2f(-5.0, 40.0);
		glVertex2f(-15.0, 25.0);
		glVertex2f(-5.0, 10.0);
		glVertex2f(-20.0, 20.0);
		glVertex2f(-35.0, 10.0);
		glVertex2f(-25.0, 25.0);
		glVertex2f(-35.0, 40.0);
	glEnd();
}

void DesenhaEstrela6()
{
	//Estrela 6
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-40.0, 20.0);
		glVertex2f(-25.0, 30.0);
		glVertex2f(-35.0, 15.0);
		glVertex2f(-25.0, 0.0);
		glVertex2f(-40.0, 10.0);
		glVertex2f(-55.0, 0.0);
		glVertex2f(-45.0, 15.0);
		glVertex2f(-55.0, 30.0);
	glEnd();
}

void DesenhaEstrela7()
{

	//Estrela 7
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-10.0, -25.0);
		glVertex2f(5.0, -15.0);
		glVertex2f(-5.0, -30.0);
		glVertex2f(5.0, -45.0);
		glVertex2f(-10.0, -35.0);
		glVertex2f(-25.0, -45.0);
		glVertex2f(-15.0, -30.0);
		glVertex2f(-25.0, -15.0);
	glEnd();

}

// Função para desenhar o sol/lua
void DesenhaEsfera() {
	glPushMatrix();
		glutSolidSphere(radius, 100, 100);
	glPopMatrix();
}

// Função para desenhar o robô
void DesenhaRobo()
{
	//Desenha o corpo do robô
	glColor3f(0.5f, 0.5f, 0.6f);
	glPushMatrix();
		glTranslated(0, 0, 40);
		glutSolidCube(50.0f);
	glPopMatrix();

	//Desenha a cabeça do robô
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
		glTranslated(0, 35, 30);
		glutSolidCube(25.0f);
	glPopMatrix();

	//Desenha o braço direito do robô
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
		glTranslated(-25, 10, 30);
		glutSolidCube(20.0f);
	glPopMatrix();

	//Desenha o braço esquerdo do robô
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
		glTranslated(25, 10, 30);
		glutSolidCube(20.0f);
	glPopMatrix();

	//Desenha o pé esquerdo do robô
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
		glTranslated(-15, -25, 30);
		glutSolidCube(20.0f);
	glPopMatrix();

	//Desenha o pé direito do robô
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
		glTranslated(15, -25, 30);
		glutSolidCube(20.0f);
	glPopMatrix();

	//Desenha o olho esquerdo
	glColor3f(r, g, b);
	glPushMatrix();
		glTranslated(-5, 35, 50);
		glutSolidCube(5.0f);
	glPopMatrix();

	//Desenha o olho direito
	glColor3f(r, g, b);
	glPushMatrix();
		glTranslated(5, 35, 50);
		glutSolidCube(5.0f);
	glPopMatrix();
}

void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica a viewport
	glViewport(0, 0, largura, altura);

	// Chama a função que desenha o robô e posiciona na cena
	glPushMatrix();
		glTranslated(25.0, 25.0, 10.0);
		glScaled(Erobo, Erobo, Erobo);
		glTranslated(-25.0, -25.0, 10.0);
		DesenhaRobo();
	glPopMatrix();

	// Desenha antena do robô
	DesenhaAntenaRobo();

	// Desenha a esfera que compõe a antena do robô
	glPushMatrix();
		glTranslated(0.0, 68.0, 0.0);
		DesenhaEsferaRobo();
	glPopMatrix();

	// Chama a função que desenha o sol/lua e posiciona na cena
	glColor3f(Rsol, Gsol, Bsol);
	glTranslated(-90.0, 80.0, 0.0);
	DesenhaEsfera();

	// Chama a função que desenha as estrelas, posiciona na cena e rotaciona
	if (isNight)
	{
			// Estrela 1
			glPushMatrix();
			glTranslatef(25.0, 25.0, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.3, 0.3, 0);
			glTranslatef(-25.0, -25.0, 0.0);
			DesenhaEstrela1();
			glPopMatrix();

			// Estrela 2
			glPushMatrix();
			glTranslatef(50.0, 10.0, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.17, 0.17, 0);
			glTranslatef(-50.0, -10.0, 0.0);
			DesenhaEstrela2();
			glPopMatrix();

			// Estrela 3
			glPushMatrix();
			glTranslatef(25.0, -7.5, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.17, 0.17, 0);
			glTranslatef(-25.0, 7.5, 0.0);
			DesenhaEstrela3();
			glPopMatrix();

			// Estrela 4
			glPushMatrix();
			glTranslatef(-35.0, -7.5, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.3, 0.3, 0);
			glTranslatef(35.0, 7.5, 0.0);
			DesenhaEstrela4();
			glPopMatrix();

			// Estrela 5
			glPushMatrix();
			glTranslatef(-20.0, 25.0, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.15, 0.15, 0);
			glTranslatef(20.0, -25.0, 0.0);
			DesenhaEstrela5();
			glPopMatrix();

			// Estrela 6
			glPushMatrix();
			glTranslatef(-40.0, 15.0, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.35, 0.35, 0);
			glTranslatef(40.0, -15.0, 0.0);
			DesenhaEstrela6();
			glPopMatrix();

			// Estrela 7
			glPushMatrix();
			glTranslatef(-10.0, -30.0, 0.0);
			glRotated(angulo, 0, 0, 1);
			glScaled(0.2, 0.2, 0);
			glTranslatef(10.0, 30.0, 0.0);
			DesenhaEstrela7();
			glPopMatrix();
	}

	// Chama a função que desenha o chão
	DesenhaChao();

	glFlush();
	glutSwapBuffers();
}

// Função de controle de tempo para rotacionar as estrelas
void Tempo(int value) {

	// Se estiver de noite, as estrelas vão girar
	if(isNight)
	{
		// Aumenta o ângulo de rotação
		angulo += 1.0f;
		if (angulo > 360.0f)
			// Garante que o ângulo permaneça dentro de 360 graus
			angulo -= 360.0f;
	}
		glutTimerFunc(16, Tempo, 1);
}

void Inicializa(void)
{

	// Definindo os parâmetros da iluminação
	GLfloat luzAmbiente[4] = { 0.2, 0.2, 0.2, 1.0 };  
	GLfloat luzDifusa[4] = { 0.5, 0.5, 0.5, 1.0 };	
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat posicaoLuz[4] = { -100.0, 50.0, 100.0, 1.0 };

	// Capacidade de brilho do material
	GLfloat especularidade[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLint especMaterial = 100;

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);  // a cor de cada ponto da primitiva é interpolada a partir dos vértices

	// Define a refletância do material 
	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering

	//glClearColor(0.678, 0.847, 0.902, 1.0);
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f);

	glEnable(GL_DEPTH_TEST);   //ativa o zBuffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   //aplica o zBuffer

	angle = 45;

}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();
	// Especifica a projeção perspectiva
	gluPerspective(angle, fAspect, 0.1, 1000);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

	// Especifica posição do observador e do alvo
	gluLookAt(xc, yc, zc,  // posição da câmera
		xa, ya, za,          // posição do alvo
		xo, yo, zo);         // vetor UP da câmera
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLint largura, GLint altura)
{
	// Para previnir uma divisão por zero
	if (altura == 0) altura = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, largura, altura);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)largura / (GLfloat)altura;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	// Quando clica com o botão esquerdo fica de noite
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) { 
			isNight = true;
			// Olhos do robô acesos de noite
			r = 1.0f;
			g = 1.0f;
			b = 0.0f;
			// Muda a cor do fundo
			glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
			// Muda a cor da esfera para branco para parecer uma lua
			Rsol = 1.0f;
			Gsol = 1.0f;
			Bsol = 1.0f;
		}
	// Quando clica com o botão esquerdo fica de dia
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			isNight = false;
			// Olhos do robô apagados de dia
			r = 0.0f;
			g = 0.0f;
			b = 0.0f;
			// Muda a cor do fundo
			glClearColor(0.678, 0.847, 0.902, 1.0);
			// Muda a cor da esfera para amarelo para parecer um sol
			Rsol = 1.0f;
			Gsol = 1.0f;
			Bsol = 0.0f;
		}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do teclado
void TeclasEspeciais(int key, int x, int y)
{
	// Robô aumenta de tamanho quando a tecla up key do teclado é pressionada
	if (key == GLUT_KEY_UP) {
		Erobo = 1.3;
		DesenhaRobo();
	}
	// Robô volta ao tamanho normal quando a tecla down key do teclado é pressionada
	if (key == GLUT_KEY_DOWN) {
		Erobo = 1.0;
		DesenhaRobo();
	}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

// Função main
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(700, 100);
	largura = 600;
	altura = 500;
	ycamera = 100;
	fAspect = (GLfloat)largura / (GLfloat)altura;
	glutInitWindowSize(largura, altura);
	glutCreateWindow("Projeto Bruna e Sabrina");

	// Define a função timer 
	glutTimerFunc(16, Tempo, 1);

	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(TeclasEspeciais);
	Inicializa();
	glutMainLoop();

}