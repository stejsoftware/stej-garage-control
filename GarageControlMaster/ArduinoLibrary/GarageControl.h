#ifndef __GarageControl_h_
#define __GarageControl_h_

#ifdef SPARK
 #include "application.h"
#else
 #include "Arduino.h"
#endif

// This is the list of recognized commands. These can be commands that can either be sent or received. 
// In order to receive, attach a callback function to these events
enum GC
{
  GC_Acknowledge,     // 0
  GC_Error,           // 1
  GC_Temperature,     // 2
  GC_DoorStatus,      // 3
  GC_PushButton,      // 4
  GC_CloseDoor,       // 5
  GC_OpenDoor,        // 6
  GC_GetTemperature,  // 7
  GC_GetDoorStatus,   // 8
};

enum DS
{
  DS_Unknown, // 0
  DS_Open,    // 1
  DS_Opening, // 2
  DS_Closed,  // 3
  DS_Closing  // 4
};

enum DOOR_COMMAND {
  DC_NONE,
  DC_OPEN_DOOR,
  DC_CLOSE_DOOR
};

struct Response
{
  GC code;
  uint32_t value;
};

String toString(DS e)
{
  switch( e )
  {
    case DS_Unknown:
      return "Unknown";
    case DS_Open:
      return "Open";
    case DS_Opening:
      return "Opening";
    case DS_Closed:
      return "Closed";
    case DS_Closing:
      return "Closing";
  }
  
  return "??";
}

Print & operator<<(Print & ps, DS e)
{
  ps.print(toString(e));
  return ps;
}

String toString(DOOR_COMMAND e)
{
  switch( e )
  {
    case DC_NONE:
      return "NONE";
    case DC_OPEN_DOOR:
      return "*** Opening ***";
    case DC_CLOSE_DOOR:
      return "*** Closing ***";
  }
  
  return "??";
}

Print & operator<<(Print & ps, DOOR_COMMAND e)
{
  ps.print(toString(e));
  return ps;
}

String toString(GC e)
{
  switch( e )
  {
    case GC_Acknowledge:
      return "GC_Acknowledge";
    case GC_Error:
      return "GC_Error";
    case GC_GetTemperature:
      return "GC_GetTemperature";
    case GC_Temperature:
      return "GC_Temperature";
    case GC_GetDoorStatus:
      return "GC_GetDoorStatus";
    case GC_DoorStatus:
      return "GC_DoorStatus";
  }

  return "??";
}

Print & operator<<(Print & ps, GC e)
{
  ps.print(toString(e));
  ps.print(" (");
  ps.print(e);
  ps.print(")");
  
  return ps;
}

Print & operator<<(Print & ps, const Response & r)
{
  ps.print("code: ");
  ps << r.code;
  ps.print("; value: ");
  ps.print(r.value);
  
  return ps;
}

#endif // __GarageControl_h_
