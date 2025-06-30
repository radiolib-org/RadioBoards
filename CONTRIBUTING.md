# Contributing to RadioLib

First of all, thank you very much for taking the time to contribute! All feedback and ideas are greatly appreciated.
To keep this library organized, please follow these rules.

## Adding new boards

This repository is intended as a crowd-sourced information database. As such, we gladly accept contributed board definitions, preferably in the form of a pull request. When adding a new board, please follow the steps below:

1. The easiest starting point is to copy-paste an existing board definition in `src/maintained`. Boards in this directory are created by RadioLib core team, which (usually) means that a team member has the hardware on hand and is actively using it, thus ensuring the definition should be correct.
2. All user-contributed board definitions should be placed in `src/contributed`. The internal structure is self-explanatory - boards are sorted by manufacturer, each board has its own header file.
3. Make sure to include source of information in the board definition header file - for example, a link to the manufacturers website.
4. To support board auto detection, add the necessary macro checks to `src/RadioBoards.h`. Again, existing boards should help you.
5. Add entry to `keywords.txt`. This file is used by Arduino IDE for syntax highlighting. **Please note that the file uses true tabs, not spaces!**
6. Before sending a pull request, check your board and the  auto-detection mechanism works.

## Issues

The following rules guide submission of new issues. These rules are in place mainly so that the issue author can get help as quickly as possible.

1. **Questions are welcome, spam is not.**  
Any issues without description will be considered spam and as such will be **CLOSED** and **LOCKED** immediately!
2. **This repository has issue templates.**  
To report bugs or suggest new features, use the provided issue templates. Use the default issue only if the templates do not fit your issue type.
3. **Be as clear as possible when creating issues.**  
Issues with generic titles (e.g. "not working", "lora", etc.) will be **CLOSED** until the title is fixed, since the title is supposed to categorize the issue. The same applies for issues with very little information and extensive grammatical or formatting errors that make it difficult to find out what is the actual issue.
