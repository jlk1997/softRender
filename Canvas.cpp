#include "Canvas.h"
#include <math.h>
namespace GT {
	void GT::Canvas::drawLine(intV2 pt1, intV2 pt2, RGBA _color)
	{
		//偏移量 目标点与起点之间
		int disY = abs(pt2.y - pt1.y);
		int disX = abs(pt2.x - pt1.x);

		//设置当下位置
		int xNow = pt1.x;
		int yNow = pt1.y;

		//步进长度
		int stepX = 0;
		int stepY = 0;

		//判断并设置步进方向
		if (pt1.x < pt2.x) {
			stepX = 1;
		}
		else {
			stepX = -1;
		}
		if (pt1.y < pt2.y) {
			stepY = 1;
		}
		else {
			stepY = -1;
		}


		//选取主步进长度，通过斜率是否>1来判断
		int sumStep = disX;//总步进次数，每次只步进1
		bool useXStep = true;//是否采用x步进方向
		if (disX < disY) {	 //当x的偏移量小于y的偏移量时，斜率就会大于一，那么此时主步进方向就为y
			sumStep = disY;		//将y长设为主要步进，每一次y都会固定+1，而x则需要根据d来计算增加（相反情况）
			useXStep = false;
			SWAP_INT(disX,disY);
		}
		
		//初始化d值（D1与D2差的正负）
		int p = 2 * disY - disX;
		for (int i = 0; i < sumStep; i++) {
			drawPoint(xNow,yNow,_color);
			if (p >= 0) {	//选取上面的点，当p<0时，次步进方向前进
				if (useXStep) {
					yNow += stepY;
				}
				else {
					xNow += stepX;
				}
				p = p - 2 * disX;
			}
			//主步进方向
			if (useXStep) {
				xNow += stepX;
			}
			else {
				yNow += stepY;
			}
			p = p + 2 * disY;
		}
		//
	}

}
