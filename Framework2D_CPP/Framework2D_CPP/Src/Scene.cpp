#include "Scene.h"

Scene::Scene()
{
	this->_screenW = 0;
	this->_screenH = 0;
	this->isFirstRun = true;
	//fwGetDisplayMode(this->screenW, this->screenH);
}

Scene::Scene(int screenW, int screenH)
{
	this->_screenW = screenW;
	this->_screenH = screenH;
	this->isFirstRun = true;
}

Scene::~Scene()
{

}

int Scene::getIndex()
{
	return _index;
}

void Scene::Init()
{

}

void Scene::Update()
{

}

void Scene::Render()
{

}

void Scene::Destroy()
{

}

void Scene::OnKeyDown(int key)
{

}

void Scene::OnMouseDown()
{

}

void Scene::OnMouseOver()
{

}