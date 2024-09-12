#include<windows.h>
using namespace std;
signed main(){
	while(1){
		if(GetAsyncKeyState(0x70))
			system("taskkill /im StudentMain.exe /f /t");
	}
	return 0;
}
