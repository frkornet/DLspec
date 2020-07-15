
#include "/Users/frkornet/Education/Coursera/DLspec/cpp/matrix.hpp"

template<typename T, size_t N>
template<typename... Exts>
Matrix<T,N>::Matrix(Exts... exts)
   :desc(exts...),                                              // copy extents
   elements(desc.size)    // allocate desc.size elements and default initialize
{}




