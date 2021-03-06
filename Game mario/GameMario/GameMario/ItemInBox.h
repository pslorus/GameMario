﻿#pragma once
#include "GameObject.h"
#include "StateMachine.h"
#include <vector>
using namespace std;

class ItemInBox : public GameObject
{
private:
	StateMachine<ItemInBox>*	m_stateMachine;

	LuckyBoxsType				m_type;
	bool						m_finishAnimation;

	int							m_currentFrame;
	vector<Frame>				m_frameList;
public:
	ItemInBox(LuckyBoxsType type);
	~ItemInBox();

	StateMachine<ItemInBox>*	getStateMachine(){ return m_stateMachine; };

	bool					isCollision(GameObject*);

	Box				getBouding();

	void			update();
	void			updateVelocity();
	void			draw(LPD3DXSPRITE SpriteHandler);

	void			setCurrentFrame(int frame);
	int				getCurrentFrame(){ return m_currentFrame; }

	int				getSizeFrameList(){ return m_frameList.size(); }

	bool			finishAnimation(){ return m_finishAnimation; }
	void			setFinishAnimation(bool x){ m_finishAnimation = x; }

	void			setItemType(LuckyBoxsType type);
	LuckyBoxsType	getItemType(){ return m_type; }

	int				m_time; // thời gian xác định vận tốc
	Vector2			(*m_mathematical)(int, float v, float alpha);// con trỏ hàm
};

