Current Version: 0.3.0
Updated: 01/27/2023

0.1.0: Auto rolls stats, organizes stats for class, sets save roll stats, sets armor and weapon proficiencies, sets hit die, boosts stats based on race, sets starting health.
0.1.1: Saves are displayed as the stat name rather than their array location. Languages are assigned and extra languages can be choosen when appropriate.
0.2.0: Refactored code.
0.2.1: Race, Class, and Background selection are no longer case-sensitive. Bard can now choose 3 Instruments. Monk can now choose an Artisan's Tool or an Instrument. Stats output now shows the order of stats.
0.2.2: Speed now gets assigned. When selecting languages, only valid options will be accepted and languages provided by race no longer show up as an option when choosing background language(s). Fixed instrument list for Bard.
0.2.3: Provided Cleric, Fighter, Monk, and Warlock much needed customization options. Skills are now assigned.
0.2.4: Made fillStats more efficient.
0.3.0: Refactored code and disabled most classes for repairs. Cleared up known performance issues because by functions doing too many tasks and using if/switch statements for string comparison.

Known Issues:
Skills need to remove options already selected.
Starting Equipment is not assigned.
Starting Spells are not assigned.
Still have some if statements for string comparison mostly in _class::setStats().
