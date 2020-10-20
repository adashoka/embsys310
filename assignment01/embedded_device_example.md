device: 
driver assist chips in autonomous, or semi-autonomous cars



working: 
provide feedback to the driver by constatly monitoring the signals
from the environment. The signals gathered from the environment could be
through cameras, radars, break temperature, tire preassure, etc. The
feedback to the driver could range from taking complete control of the car (in
case of emergency) to gentle reminder to the driver.



challenges: 
[1] Reliability: a faulty operation could endanger the lives. Designing these system 
for extreme reliability is important. Redundancy would be one of the ways of
accomplishing the reliability goals. And, with redundancy comes the challenges
of synchronizing internal states of the two computers in case of a failure.
The synchronization and handing off control from the primary computer to the
secondary computer in case of failure will be challenging

[2] Prioritization: the device should be smart enough to treat different
signals from the environment with different priorities.

[3] Response time: the device can't be sluggish in responding to signals from
the environment

[4] Test and Debug: Test and debug with limited debug registers will make this challenging

[5] Verification/Validation: Simulating all possible real world scenario will make the 
testing and validation effort challenging

[6] Response time test: The device needs to respond within a fixed time. This means 
the device needs to be tested under worst case conditions -- where there are multiple
high priority signals from the environment all happening at the same time. Designing
unit tests that simulate these conditions will be challenging. 