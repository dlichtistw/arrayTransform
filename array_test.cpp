#include <array>
#include <cassert>

#include "array_transform.h"

using namespace array_transform;

namespace
{
  char f( const int i ){ return 'a' + i; }
  
  void empty_array()
  {
    static_assert( std::is_same_v< decltype( transform( std::array< int, 0 >{}, &f ) ), std::array< char, 0 > > );
  }

  void simple_array()
  {
    const auto transformed = transform( std::array{ 0, 1, 2, 3 }, &f );
    const std::array expectation{ 'a', 'b', 'c', 'd' };

    static_assert( std::is_same_v< decltype( transformed ), decltype( expectation ) > );
    assert( transformed == expectation );
  }
}

int main()
{
  empty_array();
  simple_array();
}
