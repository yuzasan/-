#pragma once

#include"../Base/Base.h"
#include "fmfmap.h"

//�����`�b�v�ԍ�
#define NULL_TIP 255

/// <summary>
/// �}�b�v�`�b�v�ɂ��}�b�v�N���X
/// </summary>
class Map : public Base, CFmfMap {
private:

	CImage m_map_tip[2];		//�摜�I�u�W�F�N�g
	CImage m_backGround;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="nextArea">��������G���A�ԍ�</param>
	/// <param name="nextplayerpos">�v���C���[�̊J�n�ʒu</param>
	Map(int nextArea, const CVector2D& nextplayerpos);
	~Map();
	void Draw();

	/// �w�肵�����W�̃`�b�v�ԍ����擾
	/// </summary>
	/// <param name="pos">���W</param>
	/// <param name="tx">(out)��</param>
	/// <param name="ty">(out)�s</param>
	/// <returns></returns>
	int GetTip(const CVector2D& pos, int* tx = nullptr, int* ty = nullptr);

	/// <summary>
	/// �w�肵���s�Ɨ�̃`�b�v�ԍ����擾
	/// </summary>
	/// <param name="x">�s</param>
	/// <param name="y">��</param>
	/// <returns></returns>
	int GetTip(int x, int y);


	/// <summary>
	/// �}�b�v�Ƃ̔���
	/// </summary>
	/// <param name="pos">�ʒu</param>
	/// <returns>�Փ˂����`�b�v�ԍ�</returns>
	int CollisionMap(const CVector2D& pos);

	/// <summary>
	/// �}�b�v�Ƃ̔���
	/// </summary>
	/// <param name="pos">�ʒu</param>
	/// <param name="pos">��`</param>
	/// <param name="rev_pos">�Փˌ�A�C�������ʒu</param>
	/// <returns>�Փ˂����`�b�v�ԍ�</returns>
	int CollisionMap(const CVector2D& pos, const CRect& rect, CVector2D* rev_pos);
};