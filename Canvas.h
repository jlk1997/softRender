#pragma once
#include "GTMATH.h"
#include "string.h"
namespace GT {
	//用RGBA struct来表示一个像素
	//windows中是认BGRA，而不是RGBA
	struct RGBA {
		byte m_b;
		byte m_g;
		byte m_r;
		byte m_a;

		RGBA(byte _r = 255,byte _g = 255,byte _b = 255,byte _a = 255) :
		m_r(_r),m_g(_g),m_b(_b),m_a(_a)
		{
			
		}
	};

	class Canvas
	{
	private:
		int m_width;
		int m_height;
		RGBA* m_buffer;

	public:
		Canvas(int _width, int _height, void* _buffer) {
			if (_width < 0 || _height < 0) {
				m_width = -1;
				m_height = -1;
				m_buffer = nullptr;
			}

			m_buffer = (RGBA*)_buffer;
			m_width = _width;
			m_height = _height;
		}
		~Canvas() {};
		void clear() {
			if (m_buffer != nullptr) {
				memset(m_buffer,0,sizeof(RGBA)*m_width*m_height);
			}
		}
		void drawPoint(int x,int y,RGBA _Color) {
			if (x < 0|| x >= m_width || y < 0 || y >= m_height) {			//如果范围超过画布，就不画
				return;
			}
			m_buffer[y * m_width + x] = _Color;								//第y行 位置位于y*width + x处 
		}
		void drawLine(intV2 pt1,intV2 pt2,RGBA _color);
	};

}

