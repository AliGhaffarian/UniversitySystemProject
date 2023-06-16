#ifndef INPUTUTILITY
#define INPUTUTILITY
   void MakeUpperCase(std::string& text)//convert first letter to uppercase
   {
        if(text[0] >= 97 && text[0] <= 122){
             text[0] -=  32;
        }
   }

   void MakeLowerCase(std::string& text)//convert first letter to uppercase
   {
        if(text[0] >= 65 && text[0] <= 90){
             text[0] +=  32;
        }
   }


#endif // INPUTUTILITY
