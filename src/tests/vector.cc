#include <vector>
#include <pair>
#include <iostream>

int 
main( int argc, char **argv )
{
  std::vector< std::pair<float,float> > points;
  float x1=0,y1=0,x2=1,y2=1;
  points.push_back( std::make_pair(x1,y1) );
  points.push_back( std::make_pair(x2,y2) );
  for(int i = 0; i < 65536; i++) {
    size_t size = points.size();
    float x = points[0].first;
    float y = points[0].second;
    x = points[1].first;
    y = points[1].second;
  }
  return( 0 ); 
}
