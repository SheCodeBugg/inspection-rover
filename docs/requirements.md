# Requirements

What "patrol", "detect" and "secure" mean for this project, written so each one can be tested.

## Patrol

- R1. The rover follows a marked aisle route past 4 racks without human help.
- R2. The rover stops at each rack and identifies which rack it is.
- R3. The rover stops before hitting an obstacle and resumes when it is cleared.

## Detect

- R4. At each rack, the rover reads the equipment's surface temperature.
- R5. The rover flags a rack whose warning LED is solid red or blinking.
- R6. A detected fault reaches my phone within 5 seconds.

## Secure (v2)

- R7. Commands and data travel encrypted (TLS).
- R8. The rover rejects commands that weren't sent by the authorized dashboard.
- R9. The rover rejects replayed copies of earlier valid commands.
- R10. No passwords or keys are stored in plain text in the firmware or repo.

## Out of scope

- Real server hardware (mock racks with LEDs stand in)
- Outdoor or uneven terrain
- Mapping unknown spaces (route is pre-marked)
