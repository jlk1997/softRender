#include "Canvas.h"
#include <math.h>
namespace GT {
	void GT::Canvas::drawLine(intV2 pt1, intV2 pt2, RGBA _color)
	{
		//ƫ���� Ŀ��������֮��
		int disY = abs(pt2.y - pt1.y);
		int disX = abs(pt2.x - pt1.x);

		//���õ���λ��
		int xNow = pt1.x;
		int yNow = pt1.y;

		//��������
		int stepX = 0;
		int stepY = 0;

		//�жϲ����ò�������
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


		//ѡȡ���������ȣ�ͨ��б���Ƿ�>1���ж�
		int sumStep = disX;//�ܲ���������ÿ��ֻ����1
		bool useXStep = true;//�Ƿ����x��������
		if (disX < disY) {	 //��x��ƫ����С��y��ƫ����ʱ��б�ʾͻ����һ����ô��ʱ�����������Ϊy
			sumStep = disY;		//��y����Ϊ��Ҫ������ÿһ��y����̶�+1����x����Ҫ����d���������ӣ��෴�����
			useXStep = false;
			SWAP_INT(disX,disY);
		}
		
		//��ʼ��dֵ��D1��D2���������
		int p = 2 * disY - disX;
		for (int i = 0; i < sumStep; i++) {
			drawPoint(xNow,yNow,_color);
			if (p >= 0) {	//ѡȡ����ĵ㣬��p<0ʱ���β�������ǰ��
				if (useXStep) {
					yNow += stepY;
				}
				else {
					xNow += stepX;
				}
				p = p - 2 * disX;
			}
			//����������
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
