# EADP
## Electronic Aid for Detection of Pneumonia
---
### The Identified Problem
According to the World Health Organisation, pneumonia is the single largest infectious cause of death in children worldwide. Therefore, effective diagnosis and treatment of pneumonia is critical to improve child survival.
For children under the age of 5 years, pneumonia is diagnosed by the presence of either fast breathing or by the occurrence of retraction of the lower chest wall during inhalation. In a healthy body, the chest expands during inhalation. 
For the case of fast breathing, the diagnosis is done with the aid of electronic devices that help in the measurement of respiratory rate and subsequently provide information of the nature of the breathing.
The industrial devices for this purpose are usually expensive and/or difficult to use. Although there are low-cost devices available, they tend to suffer from some design issues such as wearing down of parts after repeated usage, as well as high battery consumption. There exists an opportunity to introduce an improved design whilst simultaneously bringing down the costs.
Thus, this project's goal is to produce a low-cost, accessible, and user-friendly device that has the additional benefits of being easily manufacturable and repairable.

Source of Information: [Pneumonia, World Health Organisation](https://www.who.int/news-room/fact-sheets/detail/pneumonia)

### The Proposed Solution
The proposed solution is a pocketable device that can be operated with one hand. The device contains a rotary dial/knob that controls the blinking rate of an LED. This blinking rate should be matched with the chest movement of the child. Without delay, the respiratory rate can be identified by observing the pointed number situated atop the rotary dial.

All of my initial ideas relied on manual operation, an approach whose downsides I failed to recognise. Our mentor, Prof Bhaduri mentioned an alternative approach of using an LED whose blinking speed can be controlled with a rotary knob. Upon comprehending the simplicity behind this idea, I subscribed to it, and thus arose the current design.

The low-cost device proposed would be used extensively in hospitals and homes. The expected end-user includes all healthcare workers, with the primary end-user being the ASHA health workers.

### Components
_Potentiometer:_
The controlling-knob is a central piece of the hardware. Known as a potentiometer, the device works on the principle of variable resistance, where each position of the knob is mapped to a specific resistance value within the range of 0 and 1024.

_Circuit Design:_
Connections are made in parallel to prevent the occurrence of voltage drop.

_Arduino:_
The micro-controller's functions operate on the time-scale of milliseconds. The board enables 

_LED:_
LEDs function on the principle of electroluminescence. Minority and majority charge carriers mix at the junction when a current flows through the diode and photons are produced as a result of recombination, which releases energy. The light intensity grows and reaches a maximum as the forward voltage rises, hence illuminating the LEDs.

### Evaluation of the Proposed Solution
_Pros_
1. Provides instantaneous reading of breath count
2. Prevents fatigue and is user-friendly
3. Longevity (akin to that of a pocket calculator)

_Cons_
1. Difficult to manufacture
2. There is a short learning-curve
3. Momentary fluctuations in respiratory rate is a common occurrence. Therefore, matching the light's blinking rate on the first attempt may not always provide conclusive information.

### Current-Day Solutions Used in the Field
1. The 'Respiratory Rate Timer (Mark 2) for Acute Respiratory Infections (ARI)' is a UNICEF-issued one-minute timer for keeping track of breath count. It costs ₹ 300.
2. 'RRate' is an Android app that provides pictorial representation of the baby's condition. The app is free to use.
3. Commercial IoT device that offers multiple health and safety features. It costs ₹ 10,000.

### Academic Literature
Performance of Four Respiratory Rate Counters to Support Community Health Workers to Detect the Symptoms of Pneumonia in Children in Low Resource Settings: A Prospective, Multicentre, Hospital-Based, Single-Blinded, Comparative Trial Baker, Kevin et al. eClinicalMedicine, Volume 12, 20 - 30. https://doi.org/10.1016/j.eclinm.2019.05.013

The above research paper investigates the efficacy of varied solutions for counting of a child's breath. I was very surprised to learn that none of the solutions proved reliable, and there did not arise any one superior solution. This reminded me about the importance of communicating with the end-users and obtaining their feedback.
It is from this paper that I came to know about the UNICEF-issued counting device, and the app-based solution. I also learnt about the applications of traditional indigenous tools such as counting beads. This is a very good example of a commonly existing item re-imagined for modern times.

### List of Parts Used
- Arduino Uno board
- Potentiometer
- LEDs
- Resistors
- Bread board
- Connecting wires

### List of Tools Used
Software
- Tinkercad
- Fusion 360
- Ultimaker Cura

Hardware
- Creality Ender-3 3D Printer
- Soldering gun
- Glue gun

Materials
- Polylactic Acid (PLA) thermoplastic polymer

### Testing
A few juniors participated enthusiastically in a short trial experiment. However, upon observing their difficulty in using the device, and the long durations, I was left discouraged.
The device also performed less favourably to the conventional method of verbal counting.

### Pending Work
The current prototype has been assembled completely. It has highlighted the need for future designs to include screw mounts and replace the current casing's top with an enclosure. This will negate the need for the high volume of tape used at present.
The button to jump the LED directly to peak brightness is functional but not accurate.
Numbers have been detailed surrounding this dial as well. The hand-drawn numbers could be replaced with a printed sticker.
Additionally, the battery-case could be lifted for improved access to the switch.

### The Ideal Solution
The current prototype is large and therefore requires a two-hand operation. Instead of an Arduino board, a simple microcontroller with a timer should be used. To ensure that the device can be used by any individual, the language and literacy barriers must be overcome with the usage of pictorials and illustrations.
Thus, the ideal solution for the device would be a pocketable form-factor that follows good design principles, with universal accessibility.

### Sources of Inspiration
While reading the Indian Express, a particular headline caught my eye. The [article](https://indianexpress.com/article/technology/tech-news-technology/loss-of-friend-inspires-dehradun-techie-to-develop-portable-ecg-device-smartphone-8265434/) featured the story of a medical-grade low-cost ECG called 'Spandan', a device developed by a company called Sunfox Technologies.

Notwithstanding the origin story of this device, I find its design to be thoughtful, novel, and well-executed. Four years is indeed a long time for development, but the quality of the product justifies this time period. Similar to the 'Sense-U' baby monitoring device that I had written about earlier, this device takes the route of hardware-software integration.
On its own, the device has no utility, as it requires a smartphone for power supply, and data logging. This opens up a world of possibilities, and is simultaneously a limiting factor on the usability of the device.
Last but not the least, I should take inspiration on how to name a device. 'Spandan' certainly has a much nicer ring to it than 'EADP'.
