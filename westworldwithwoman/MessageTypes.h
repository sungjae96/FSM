#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_BobAttack,
  Msg_ElsaAttack,
  Msg_Found
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_BobAttack:

	  return "BobAttack";

  case Msg_ElsaAttack:

	  return "ElsaAttack";

  case Msg_Found:

	  return "Found";

  default:

    return "Not recognized!";
  }
}

#endif