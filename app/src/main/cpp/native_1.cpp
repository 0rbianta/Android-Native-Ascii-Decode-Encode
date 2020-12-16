#include <jni.h>
#include <string>

using namespace std;

string charToString(char data);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_native_1example_1ascii_1converter_MainActivity_text2ascii(JNIEnv *env, jobject thiz, jstring plain_text) {

    string text_cpp = env->GetStringUTFChars(plain_text,0);

    string asciis;
    for(int i=0;i<text_cpp.size();i++){

        asciis+=to_string(text_cpp[i])+",";

    }

    asciis=asciis.substr(0, asciis.size()-1);

    return env->NewStringUTF(asciis.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_native_1example_1ascii_1converter_MainActivity_ascii2text(JNIEnv *env, jobject thiz, jstring asciis_j) {

    string asciis = env->GetStringUTFChars(asciis_j,0);

    asciis+=",";

    string text;
    string proc_ascii;
    for(int i=0;i<asciis.size();i++){

        string proc_char = charToString(asciis[i]);

        if(proc_char!=","){

            proc_ascii+=proc_char;

        }else{

            string proc_char_ = charToString(stoi(proc_ascii));
            text+=proc_char_;
            proc_ascii="";

        }

    }

    return env->NewStringUTF(text.c_str());
}


string charToString(char data){
    string x;
    x=x+data;
    return x;
}