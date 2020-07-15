/*
File: matrix.h

Description:


*/

#include <stddef.h>

template<typename T, size_t N>
class Matrix {
public:
  // number of dimensions
  static constexpr size_t order = N;
  using value_type = T;
  using iterator = typename std::vector<T>::iterator ;
  using const_iterator = typename std::vector<T>::const_iterator;

  Matrix() = default ;
  
  Matrix( Matrix&& ) = default ;                                        // move
  Matrix& operator=(Matrix&&) == default ;
  
  Matrix( const Matrix& ) = default ;                                   // copy
  Matrix& operator=( const Matrix& ) = default ;
  
  ~Matrix() = default ;

  template<typename U>
  Matrix( const Matrix_ref<U,N>& ) ;               // construct from Matrix_ref

  template<typename U>
  Matrix& operator=(const Matrix_ref<U,N>&) ;         // assign from Matrix_ref

  template<typename..Exts>
  explicit Matrix(Exts..exts) ;                          // specify the extents

  Matrix( Matrix_initializer<T,N> ) ;                   // initialize from list
  Matrix& operator=( Matrix_initializer<T,N> ) ;            // assign from list

  template<typename U>
  Matrix(initializer_list<U>) = delete;     // don't use {} except for elements

  template<typename U>
  Matrix& operator=(initilizer_list<U>) = delete ;

  // # elements in the nth dimension
  size_t extent(size_t n) const { return desc.extents[n] ; }
  // total number of elements  
  size_t size() const { return elems.size() ; } 
  // the slice defining subscripting              
  const Matrix_slice<N>& descriptor() const { return desc ; } 

  T* data() { return elems.data() ; }                  // "flat" element access
  const T* data() const { return elems.data(); }

  // ...

private:
  Matrix_slice<N> desc ;        // slice containing extents in the N dimensions
  vector<T> elems ;                                             // the elements
} ;

