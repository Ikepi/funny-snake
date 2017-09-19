// funnysnake.cpp : 定义控制台应用程序的入口点。

//根据上个学期期末大作业俄罗斯方块，改成贪吃蛇，基本实现了贪吃蛇的功能。

#include "stdafx.h"

#include <iostream>

#include "BlackBoard.h"
#include "UIController.h"

// 提供绘图环境的对象
BlackBoard board;

void ReshapeCallback(int width, int height)
{
	board.UpdateWindowSize(width, height); 
}

// 定时器回调函数，具体功能逻辑交由UIController处理
void TimerCallback(int value)
{
	UIController::handle().OnTimer(value); 

	// GameSpeed在UIController中，可用于控制难度
	board.InstallTimerCallback(UIController::handle().GameSpeed(), TimerCallback, value); 
}

// 窗口用于处理键盘输入的回调函数入口，具体功能逻辑交由UIController处理
void KeyboardCallback(unsigned char key, int x, int y)
{
	UIController::handle().OnKey(key, x, y); 
}

// 窗口用于绘制的回调函数入口，具体功能逻辑交由UIController处理
void DisplayCallback()
{
	board.Clear(); 

	UIController::handle().OnDraw(board); 
	
	board.Flush(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 以下代码用于初始化窗口等、可忽略
	board.InitCommandLine(&argc, (char **)argv); 
	board.InitWindowSize(600, 600); 

	board.InitDisplayCallback(DisplayCallback); 
	board.InitKeyboardCallback(KeyboardCallback); 
	board.InitReshapeCallback(ReshapeCallback); 

	board.InstallTimerCallback(UIController::handle().GameSpeed(), TimerCallback, 0);
	
	board.Show(); 

	return 0;
}

