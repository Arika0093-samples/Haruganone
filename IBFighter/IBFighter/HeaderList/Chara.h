#ifndef H_CHARA
#define H_CHARA

#include "Constant.h"

//�L�����N�^�[�N���X
class Chara
{
private :
	int handle[C_MAX_HANDLE];	//�e�X�N�`���n���h���ݒ�
	int se[C_MAX_SE];			//�L�������Ƃ�SE�n���h��
public :
	int x;						//�L����x���W
	int y;						//�L����y���W

	Chara();					//�R���X�g���N�^

	void Load();				//0�Ԗڂ����[�h	(�����g�p���Ȃ��ꍇ�͂�����)
	void Load(int num);			//num�Ԗڂ����[�h

	void Update();				//�l�X�Ȍv�Z����
	void Draw();				//�L������`��
};

#endif