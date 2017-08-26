#include <random>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <class T>
vector <T> get_rand_vector(const T & n){
  //std::shared_ptr <int> p = &n; // smart pointer does not need to be deallocated.
  
  mt19937 rng;
  rng.seed(random_device()());
  uniform_int_distribution<mt19937::result_type> dist6(1,6); // distribution in range [1, 6]                                 
  

  vector <T> out;

  //  array <int, n> out_array; compilation error because array needs to know size of array at compilation time, n is argument!

  for(int i=0; i<n; i++){
    out.push_back(dist6(rng));
    //    cout << dist6(rng) << endl;
  }
  
  return out;
}

template <class T>
vector <T> apply_fn_to_vector(const vector <T>& v, 
				const function <T(T)> f) // function that takes int as argument and returns int: int(int)
{
  vector <T> out;
  for (auto e:v)
    out.push_back(f(e));

  return out;
}

template <class T>
void print_vec(const vector <T>& v){
  for (auto e:v)
    cout << e << endl;
}

template <class T>
void exercise(){
  //vector <int> v = get_rand_vector(10);                                                                                                   
  auto v = get_rand_vector<T>(10);

  for(int i=0; i<v.size(); i++)
    cout << v[i] << endl;

  //vector<double>::iterator it = v.begin();                                                                                                
  auto it = v.begin();
  //const vector<int>::iterator et = v.end();                                                                                               
  const auto et = v.end();

  for(; it !=et; ++it)
    cout << *it << endl;

  for(auto e:v)
    cout << e << endl;

  // LAMBDA FUNCTION DEFINITION                                                                                                             
  function <T(T)> f = [](T i){
    return i*i;
  };

  print_vec(apply_fn_to_vector(v,f));

  T s = 5;
  auto shift = [s](T i){
    return i+s;
  };

  print_vec<T>(apply_fn_to_vector<T>(v,shift));

} 



int main()
{
  exercise<int>();
}
