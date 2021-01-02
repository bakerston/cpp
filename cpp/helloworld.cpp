#include<iostream>
using namespace std;
/*
int main() {
	
	
	cout << "\\" << endl;
	cout << "\tHello" << endl;
	cout << "\n" << endl;

	system("pause");

	return 0;
}*/

/*
int main() {

	bool flag = true;
	cout << "请输入布尔型变量：" << endl;
	cin >> flag;
	cout << flag << endl;
	system("pause");
	return EXIT_SUCCESS;
}*/
/*
int main() {

	int score = 0;

	cout << "请输入考试分数：" << endl;

	cin >> score;

	if (score > 600)
	{
		cout << "我考上了一本大学" << endl;
	}
	else
	{
		cout << "我未考上一本大学" << endl;
	}

	system("pause");

	return 0;
}*/

/*
int main() {

	cout << "1" << endl;

	goto FLAG;

	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;

	FLAG:

	cout << "5" << endl;
	
	system("pause");

	return 0;
}*/
int main(){

   int arr[10]={1,2,3,4,5,6,7,8,9,10};
   cout<<sizeof(arr)<<endl;
   cout<<sizeof(arr[0])<<endl;
   cout<<sizeof(arr)/sizeof(arr[0])<<endl;

   cout<< &arr <<endl;
   cout<< &arr[0] <<endl;
   cout<< &arr[1] <<endl;
}
