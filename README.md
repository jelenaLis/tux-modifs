# tux-modifs

New object to send LSL message: Streamer ;)

Use "launch.sh" to run etracer with the correct library path.

LSL flags:

- when splash screen ends: OVTK_StimulationId_ExperimentStart
- when tux jumps: OVTK_StimulationId_Beep
- when a race starts: OVTK_StimulationId_SegmentStart
- when a race stops: OVTK_StimulationId_SegmentStop
- when a race is completed: OVTK_StimulationId_Train

- when a trial starts (passes by start flag): OVTK_GDF_Start_Of_Trial
  - if on left: OVTK_GDF_Left
  - if on right: OVTK_GDF_Right
- when a trial stops (passes by stop flag): OVTK_GDF_End_Of_Trial
  - if on left: OVTK_GDF_Up
  - if on right: OVTK_GDF_Down

- pass by a herring on the left: OVTK_StimulationId_Label_01
- pass by a herring on the right: OVTK_StimulationId_Label_02

- collect a herring on the left: OVTK_StimulationId_Label_03
- collect a herring on the right: OVTK_StimulationId_Label_04

- pass by a squid (star) on the left: OVTK_StimulationId_Label_05
- pass by a squid (star) on the right: OVTK_StimulationId_Label_06

- collect a squid (star) on the left: OVTK_StimulationId_Label_07
- collect a squid (star) on the right: OVTK_StimulationId_Label_08