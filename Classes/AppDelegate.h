#pragma once

/*
EliminatePest所属的程序入口模块
含：
1.AppDelegate类
用途：用于打开游戏。
*/

#include "QE.h"

 /**
 @brief    The cocos2d Application.

 Private inheritance here hides part of interface from Director.
 */
class  AppDelegate : private cocos2d::Application
{
public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual void initGLContextAttrs();

	/**
	@brief    Implement Director and Scene init code here.
	@return true    Initialize success, app continue.
	@return false   Initialize failed, app terminate.
	*/
	virtual bool applicationDidFinishLaunching();

	/**
	@brief  Called when the application moves to the background
	@param  the pointer of the application
	*/
	virtual void applicationDidEnterBackground();

	/**
	@brief  Called when the application reenters the foreground
	@param  the pointer of the application
	*/
	virtual void applicationWillEnterForeground();
};