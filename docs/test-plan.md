# Test plan

How each success measure is tested. Record every run in `/log` with the date, setup and raw numbers — report results honestly, including failures.

| ID | Measure | Target | How it's tested | Stage |
| --- | --- | --- | --- | --- |
| T1 | Straight-line drift | < 5 cm over 3 m | Drive 3 m forward on a taped line, measure sideways offset with a tape measure, 5 runs | 1 |
| T2 | Obstacle avoidance | 9 of 10 runs | Obstacle course with 3 boxes; a run passes with no contact | 1 |
| T3 | Patrol completion | 10 of 10 laps | Full aisle lap with no human help | 2 |
| T4 | Rack stop accuracy | 95%+ | Count correct rack IDs over 10 laps × 4 racks = 40 stops | 2 |
| T5 | Temperature reading | Within ±2 °C | Compare with a kitchen/IR thermometer on a warm object | 2 |
| T6 | Fault detection | 90%+ of 50 | 50 trials: random rack set to red, blinking or OK; 3 lighting setups | 3 |
| T7 | Alert time | < 5 s | Timestamp detection vs phone notification, 20 trials | 3 |
| T8 | Spoofing resistance (v2) | 0 of 10 accepted | Send forged commands from an unauthorized device on my own network | 4 |
| T9 | Replay resistance (v2) | 0 of 10 accepted | Re-send captured valid commands | 4 |

Run T8 and T9 against v1 first to show the attacks work, then against v2.
