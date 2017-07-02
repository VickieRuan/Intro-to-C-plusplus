#ifndef ICT_VALIDATE_H_
#define ICT_VALIDATE_H_

namespace ict{
	template <typename T>
	bool validate(const T& min, const T& max, const T* a, const int num, bool* v){
		bool pass = true;

		for(int i=0; i < num; i++){
			if(a[i] >= min && a[i] <= max){
				v[i] = true;
			}else{
				v[i] = false;
			}
		}

		for(int i=0; i < num; i++){
			if(v[i] == false){
				pass = false;
			}
		}
		return pass;

	}


}
#endif
