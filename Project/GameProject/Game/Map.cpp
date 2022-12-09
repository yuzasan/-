
#include"Map.h"
#include"AreaChange.h"

Map::Map(int nextArea,const CVector2D& nextplayerpos) : Base(eType_Field) {
	//���C���[0
	m_map_tip[0] = COPY_RESOURCE("Yuka", CImage);
	//���C���[1
	m_map_tip[1] = COPY_RESOURCE("Kabe", CImage);
	switch (nextArea) {
	case 1:
		//fmf����}�b�v�f�[�^��ǂݍ���
		Open("Map/����.fmf");
		//�L���@�E��
		Base::Add(new AreaChange(2,					//���̃}�b�v�̔ԍ�
			CRect(m_fmfHeader.byChipWidth * 33,		//�G���A�`�F���W�̔���
				m_fmfHeader.byChipHeight * 14,		//����
				m_fmfHeader.byChipWidth * 1,		//���T�C�Y
				m_fmfHeader.byChipHeight * 13),		//�c�T�C�Y
			CVector2D(m_fmfHeader.byChipWidth * 1,	//���̃}�b�v�̍ŏ��̃v���C���[�̏ꏊ
				m_fmfHeader.byChipHeight * 20)));
		//�L���@����
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 14,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 13),
			CVector2D(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 20)));
		break;

	case 2:
		Open("Map/�L�� �E.fmf");
		//�L���@�E���
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 16,
				m_fmfHeader.byChipHeight * 9,
				m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 1),
			CVector2D(m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 30)));
		//���ւ�
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 14,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 14),
			CVector2D(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 20)));
		break;

	case 3:
		Open("Map/�L�� �E��.fmf");
		//�L���@�E��
		Base::Add(new AreaChange(2,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 34,
				m_fmfHeader.byChipWidth * 17,
				m_fmfHeader.byChipHeight * 1),
			CVector2D(m_fmfHeader.byChipWidth * 25,
				m_fmfHeader.byChipHeight * 8)));

		//�L���@���
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 6,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 13),
			CVector2D(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 16)));

		//2�K��
		Base::Add(new AreaChange(8,
			CRect(m_fmfHeader.byChipWidth * 10,
				m_fmfHeader.byChipHeight * 21,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 20,
				m_fmfHeader.byChipHeight * 5)));
		break;

	case 4:
		Open("Map/�L�� ��.fmf");
		//����
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 9,
				m_fmfHeader.byChipWidth * 18,
				m_fmfHeader.byChipHeight * 1),
			CVector2D(m_fmfHeader.byChipWidth * 15,
				m_fmfHeader.byChipHeight * 30)));
		//���ւ�
		Base::Add(new AreaChange(1,
			CRect(m_fmfHeader.byChipWidth * 33,
				m_fmfHeader.byChipHeight * 14,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 14),
			CVector2D(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 20)));

		break;

	case 5:
		Open("Map/�L�� ����.fmf");
		//����
		Base::Add(new AreaChange(4,
			CRect(m_fmfHeader.byChipWidth * 9,
				m_fmfHeader.byChipHeight * 34,
				m_fmfHeader.byChipWidth * 17,
				m_fmfHeader.byChipHeight * 1),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 9)));
		//�L���@���
		Base::Add(new AreaChange(6,
			CRect(m_fmfHeader.byChipWidth * 27,
				m_fmfHeader.byChipHeight * 6,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 13),
			CVector2D(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 16)));
		//2�K��
		Base::Add(new AreaChange(7,
			CRect(m_fmfHeader.byChipWidth * 21,
				m_fmfHeader.byChipHeight * 21,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 10,
				m_fmfHeader.byChipHeight * 10)));

		break;

	case 6:
		Open("Map/�L�� ��.fmf");
		//����
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 10,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 14),
			CVector2D(m_fmfHeader.byChipWidth * 25,
				m_fmfHeader.byChipHeight * 10)));

		//�E��
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 33,
				m_fmfHeader.byChipHeight * 10,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 14),
			CVector2D(m_fmfHeader.byChipWidth * 8,
				m_fmfHeader.byChipHeight * 10)));
		break;

	case 7:
		Open("Map/2�K ��.fmf");
		//����
		Base::Add(new AreaChange(5,
			CRect(m_fmfHeader.byChipWidth * 10,
				m_fmfHeader.byChipHeight * 15,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 21,
				m_fmfHeader.byChipHeight * 23)));
		//2�K �E1
		Base::Add(new AreaChange(8,
			CRect(m_fmfHeader.byChipWidth * 33,
				m_fmfHeader.byChipHeight * 1,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 4,
				m_fmfHeader.byChipHeight * 2)));
		//2�K �E2
		Base::Add(new AreaChange(8,
			CRect(m_fmfHeader.byChipWidth * 33,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 29)));
		break;

	case 8:
		Open("Map/2�K �E.fmf");
		//�E��
		Base::Add(new AreaChange(3,
			CRect(m_fmfHeader.byChipWidth * 20,
				m_fmfHeader.byChipHeight * 15,
				m_fmfHeader.byChipWidth * 5,
				m_fmfHeader.byChipHeight * 2),
			CVector2D(m_fmfHeader.byChipWidth * 10,
				m_fmfHeader.byChipHeight * 22)));
		//2�K ��1
		Base::Add(new AreaChange(7,
			CRect(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 1,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 31,
				m_fmfHeader.byChipHeight * 2)));
		//2�K ��2
		Base::Add(new AreaChange(7,
			CRect(m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 28,
				m_fmfHeader.byChipWidth * 1,
				m_fmfHeader.byChipHeight * 6),
			CVector2D(m_fmfHeader.byChipWidth * 30,
				m_fmfHeader.byChipHeight * 29)));
		break;
	}

	//�v���C���[�̈ʒu����
	if (Base* p = Base::FindObject(eType_Player)) {
		p->ResetPos(nextplayerpos);
	}
	
}
Map::~Map() {
	//fmf�����
	Close();
}

void Map::Draw() {
	if (m_kill) return;

	//1F�̃Y�����Ȃ������߁A�`��̒��O�ŃX�N���[���l�m��
	if (Base* p = Base::FindObject(eType_Player)) {
		//�X�N���[���ݒ�
		m_scroll.x = p->m_pos.x - 600;
		m_scroll.y = p->m_pos.y - 500;
	}


	//�`�b�v�̐��@��s�P�U�񂩁@�P�s�Q�T�U��
	int s = pow(16, (GetLayerBitCount() / 8));

	//�\���͈͂�����@��ʂɈڂ�͈͂����`��
	int col = CCamera::GetCurrent()->GetWhidth() / GetChipWidth()+1;
	int row = CCamera::GetCurrent()->GetHeight() / GetChipHeight()+1;
	
	int sx = m_scroll.x / GetChipWidth();
	if (sx < 0) sx = 0;
	int ex = sx + col;
	if (ex > GetMapWidth())ex = GetMapWidth();

	int sy = m_scroll.y / GetChipHeight();
	if (sy < 0) sy = 0;
	int ey = sy + row;
	if (ey > GetMapHeight())ey = GetMapHeight();
	

	//���C���[�������J��Ԃ� k=1����n�߂�Ɣ���p�̕ǂ����\�������
	for (int k = 0; k < GetLayerCount();k++) {
		//�s�Ɨ�̌J��Ԃ�
		for (int j = sy; j < ey; j++) {
			for (int i = sx; i < ex; i++) {
				//�`�b�v�̔ԍ����擾����
				int t = GetValue(k, i, j);
				//���ߔԍ��Ȃ�\�����Ȃ�
				if (t == NULL_TIP) continue;
				//�`�b�v�ԍ�����g�p����摜�̏ꏊ���v�Z
				int x = t % s;
				int y = t / s;
				//�\���ʒu�ݒ�
				m_map_tip[k].SetPos(CVector2D(m_fmfHeader.byChipWidth*i, m_fmfHeader.byChipHeight*j)-m_scroll);
				//�\����`�ݒ�
				m_map_tip[k].SetRect(x * m_fmfHeader.byChipWidth, y * m_fmfHeader.byChipHeight, (x + 1) * m_fmfHeader.byChipWidth, (y + 1) * m_fmfHeader.byChipHeight);
				//�T�C�Y�ݒ�
				m_map_tip[k].SetSize(m_fmfHeader.byChipWidth, m_fmfHeader.byChipHeight);
				//�\��
				m_map_tip[k].Draw();
			}
		}
	}
	
}

int Map::GetTip(const CVector2D& pos, int* tx, int* ty)
{
	//����v�Z
	int x = pos.x / GetChipWidth();
	//��̐���
	if (x < 0) x = 0;
	if (x > GetMapWidth() - 1) x = GetMapWidth() - 1;
	//�s���v�Z
	int y = pos.y / GetChipHeight();
	//�s�̐���
	if (y < 0) y = 0;
	if (y > GetMapHeight() - 1) y = GetMapHeight() - 1;
	//�s�Ɨ�̏o��
	if (ty) *ty = y;
	if (tx) *tx = x;
	//�`�b�v�f�[�^��ԋp�@�ǂ̔ԍ���Ԃ�
	return GetValue(1, x, y);
}

int Map::GetTip(int x, int y)
{
	return GetValue(1, x, y);
}


int Map::CollisionMap(const CVector2D& pos)
{
	return GetTip(pos);
}
int Map::CollisionMap(const CVector2D& pos, const CRect& rect, CVector2D* rev_pos)
{
	//�}�b�v�`�b�v�̃T�C�Y��16�h�b�g�Ə������̂ŁA�ǔ������Ȃ��悤6�_�Ŕ���
	int tx, ty;
	//����
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = (tx + 1) * GetChipWidth() - rect.m_left + 1;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = tx * GetChipWidth() - rect.m_right - 1;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}

	//�^�񒆏�
	t = GetTip(CVector2D(pos.x + (rect.m_right+ rect.m_left)/2, pos.y + rect.m_top), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = pos.x;
		rev_pos->y = (ty + 1) * GetChipHeight() - rect.m_top + 1;
		return t;
	}

	//����
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = (tx + 1) * GetChipWidth() - rect.m_left + 1;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	//�E��
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = tx * GetChipWidth() - rect.m_right - 1;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	//������
	t = GetTip(CVector2D(pos.x + (rect.m_right+ rect.m_left)/2, pos.y + rect.m_bottom), &tx, &ty);
	if (t != NULL_TIP) {
		//�C����ʒu
		rev_pos->x = pos.x;
		rev_pos->y = ty * GetChipHeight() - rect.m_bottom - 1;
		return t;
	}
	return NULL_TIP;
}