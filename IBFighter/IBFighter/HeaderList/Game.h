#ifndef H_GAME
#define H_GAME

#include <windows.h>

#include "Constant.h"

class Game{
private :
	int status;		//�Q�[����Ԃ��L��
public :
	SIZE screen;	//�N���C�A���g�̈�T�C�Y
	Game(SIZE data);			//�R���X�g���N�^

	int GetStatus();	//�Q�[���X�e�[�^�X���擾
	void SetStatus(int data);	//�Q�[���X�e�[�^�X��ݒ�



};

#endif 