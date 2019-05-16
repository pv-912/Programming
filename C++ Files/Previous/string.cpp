#include <iostream>
#include <cstring>

using namespace std;

void check_word_present(char word[], char line[]){

	int word_length = strlen(word);
	int line_length = strlen(line);

	cout<<word_length;

	// int presency;

	// for(int i; i<line_length; i++){
	// 	presency = strcmp(word,line);
	// }
	// cout<<presency<<endl;
}


int main(){
	char s[20] = "hello world";
	char s1[10] = "a";
	char s2[10] = "b";
	char *a = s;

	// cin.getline(s,sizeof(s));
	// cout<<s<<endl;

	int c = strcmp(s1,s2);
	cout<<c<<endl;

	int d = strlen(s);
	cout<<d<<endl;

	strcat(s1,s2);
	cout<<s1<<s2<<endl;

	while( *a != '\0' ){
		cout<<*a<<endl;
		a++;
	}


	// 2-D string

	char s3[10][10] = {
		"hello",
		"world",
		"prashant",
		"priya"
	};

	cout<<s3[1]<<endl;
	cout<<&s3<<endl;

	// word's presency

	char word[10] = "prashant";
	char line[50] = "My name is prashant";

	check_word_present(word,line);

}