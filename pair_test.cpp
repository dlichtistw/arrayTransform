#include <cassert>
#include <utility>

#include "array_transform.h"

using namespace array_transform;

namespace
{
  char f( const int i ){ return 'a' + i; }

  char g( const int i ){ return 'a' + i; }
  int g( const char c ){ return c - 'a'; }

  void homogeneous_pair()
  {
    const auto transformed = transform( std::pair{ 0, 1 }, &f );
    const std::pair expectation{ 'a', 'b' };

    static_assert( std::is_same_v< decltype( transformed ), decltype( expectation ) > );
    assert( transformed == expectation );
  }

  void heterogeneous_pair()
  {
    const auto transformed = transform( std::pair{ 0, 'b' }, []( const auto &t ){ return g( t ); } );
    const std::pair expectation{ 'a', 1 };

    static_assert( std::is_same_v< decltype( transformed ), decltype( expectation ) > );
    assert( transformed == expectation );
  }
}

int main()
{
  homogeneous_pair();
  heterogeneous_pair();
}
