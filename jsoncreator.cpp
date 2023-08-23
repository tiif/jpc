#include <iostream>
#include <sstream>
#include <string.h>
#include <type_traits>


/**
 * Creating json Object with primitive type value
 */
template<typename T>
class JObject {
  private:
    std::string key;
    //converted value to string
    std::string p_value;

  public:
    JObject(std::string key, T value) {
      this->key = key;
      std::stringstream s;
      s << value;
      this->p_value = s.str();
    }
    //print out json string
    std::string toString();
};

//partial template specialisation for jObject
template<>
std::string JObject<std::string>:: toString() {
   return "{\"" + key + "\" : \"" + p_value + "\"}";
}

template <typename T>
std::string JObject<T>:: toString() {
   return "{\"" + key + "\" : " + p_value + "}";
}

int main(){
  //test for string
  JObject<std::string> ob1 = JObject<std::string>("some string", "string here");
  std::cout << ob1.toString();
  std::cout << "\n";
  //test for int
  JObject<int> ob2 = JObject<int>("int", 1);
  std::cout << ob2.toString();
  std::cout << "\n";

  //test for bool
  JObject<bool> ob3 = JObject<bool>("bool statement", false);
  std::cout << ob3.toString();
  std::cout << "\n";
  
  //test for char
  JObject<char> ob4 = JObject<char>("first letter", 'a');
  std::cout << ob4.toString();
  std::cout << "\n";
}
