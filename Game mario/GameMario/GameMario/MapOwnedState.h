﻿#pragma once
#include "MapObject.h"


class MenuGame : public State < MapObject >
{
private:
	static MenuGame*	m_instance;
public:
	MenuGame(){}
	virtual ~MenuGame(){}

	static MenuGame*	getInstance();

	virtual void		enter(MapObject*);
	virtual void		execute(MapObject*);
	virtual void		exit(MapObject*);
	virtual void		draw(MapObject*, LPD3DXSPRITE);
};

class ChangeMap : public State < MapObject >
{
private:
	static ChangeMap*	m_instance;
	int					m_countTime;
public:
	ChangeMap(){}
	virtual ~ChangeMap(){}

	static ChangeMap*	getInstance();

	virtual void		enter(MapObject*);
	virtual void		execute(MapObject*);
	virtual void		exit(MapObject*);
	virtual void		draw(MapObject*, LPD3DXSPRITE);
};



struct InformationSubMap
{
	Box boxGoInSubMap; // tọa độ vào submap
	Box boxGoOutSubMap; // tọa độ khi ra khỏi submap 

	Box	boxStartSubMap; // tọa độ mario trong submap
	Box boxEndSubMap; // toa độ kết thúc submap
};

class MapOne : public State < MapObject >
{
private:
	InformationSubMap			m_subMap;

	Box m_boxStartMap; // toa độ mario xuất hiện
	Box m_boxEndMap; // tọa độ kết thúc map

	static MapOne*	m_instance;
public:
	MapOne();
	virtual ~MapOne(){}

	static MapOne*	getInstance();

	virtual void		enter(MapObject*);
	virtual void		execute(MapObject*);
	virtual void		exit(MapObject*);
};

class MapTwo : public State < MapObject >
{
private:
	InformationSubMap			m_subMap;
	InformationSubMap			m_subMapInSubMap;

	Box m_boxStartMap; // toa độ mario xuất hiện
	Box m_boxEndMap; // tọa độ kết thúc map

	static MapTwo*	m_instance;
public:
	MapTwo();
	virtual ~MapTwo(){}

	static MapTwo*	getInstance();

	virtual void		enter(MapObject*);
	virtual void		execute(MapObject*);
	virtual void		exit(MapObject*);
};

class MapThree : public State < MapObject >
{
private:
	Box m_boxStartMap; // toa độ mario xuất hiện
	Box m_boxEndMap; // tọa độ kết thúc map

	static MapThree*	m_instance;
public:
	MapThree();
	virtual ~MapThree(){}

	static MapThree*	getInstance();

	virtual void		enter(MapObject*);
	virtual void		execute(MapObject*);
	virtual void		exit(MapObject*);
};


