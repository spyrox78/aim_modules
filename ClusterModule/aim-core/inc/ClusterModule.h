/**
 * This file is created at Almende B.V. It is open-source software and part of the Common 
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from 
 * thread pools and TCP/IP components to control architectures and learning algorithms. 
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software being used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * @author               Anne C. van Rossum
 * @copyright            Distributed Organisms B.V.
 * @date                 Nov 18, 2013
 * @license              GNU General Lesser Public
 */

#ifndef CLUSTERMODULE_H_
#define CLUSTERMODULE_H_

#include <string>
#include <vector>
#include <string>
#include <vector>

namespace rur {

struct Param {
  std::string module_id;
  int parameter;
};

typedef std::vector<int> long_seq;

class ClusterModule {
private:
  Param *cliParam;
  
  long_seq dummyTrain;
  long_seq dummyTest;
protected:
  static const int channel_count = 3;
  const char* channel[3];
public:
  // Default constructor
  ClusterModule();
  
  // Default destructor
  virtual ~ClusterModule();
  
  // Extend this with your own code, first call ClusterModule::Init(name);
  void Init(std::string& name);
  
  // Function to get Param struct (to subsequently set CLI parameters)
  inline Param *GetParam() { return cliParam; }
  
  // Overwrite this function with your own code
  virtual void Tick() = 0;
  
  // Overwrite this function with your own code
  bool Stop() { return false; }
  
  // Read from this function and assume it means something
  // Remark: caller is responsible for evoking vector->clear()
  long_seq *readTrain(bool blocking=false);
  
  // Read from this function and assume it means something
  // Remark: caller is responsible for evoking vector->clear()
  long_seq *readTest(bool blocking=false);
  
  // Write to this function and assume it ends up at some receiving module
  bool writeClass(const int output);
  
};
} // End of namespace

#endif // CLUSTERMODULE_H_
