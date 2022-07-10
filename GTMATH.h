#pragma once
namespace GT {

	template<typename T>
	void swap(T& a,T& b) {
		int temp = a;
		a = b;
		b = temp;
	}
#define SWAP_INT(a,b) swap<int>(a,b);


	template<typename T> 
	struct tVec2 {
		T x;
		T y;
		
		tVec2(T _x,T _y) {
			x = _x;
			y = _y;
		}
		tVec2() {
			x = -1;
			y = -1;
		}
	};

	typedef tVec2<int> intV2;
	typedef tVec2<float> floatV2;

	typedef unsigned int uint;
	typedef unsigned char byte;

}