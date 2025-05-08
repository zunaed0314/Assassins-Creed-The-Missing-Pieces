This game was made in a much older version which is Visual Studio Professional 2013.
So at first make sure you have that version. If not, you can download it from this given link.
Now after running this game, it may give error at first. The error may say this

"Error	1	error MSB8020: The build tools for v143 
(Platform Toolset = 'v143') cannot be found. To build using the v143 build tools, please install v143 build tools.  
Alternatively, you may upgrade to the current Visual Studio tools by selecting the Project menu or right-click the solution
, and then selecting "Upgrade Solution...".	
C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V120\Microsoft.Cpp.Platform.targets"

To fix this go open the .vcxproj file(name is 'main' in D:\Assassins\Assassin_s Creed- The missing pieces\main directory)
in notepad or notepad++, then replace "<PlatformToolset>v143</PlatformToolset>" with 
"<PlatformToolset>v120</PlatformToolset>".

Now you are all set. Run the program again and you will be able to play the game. 

						    -----------------------------
							      About GAME
						    -----------------------------

1. The game has 5 levels. After finishing each level you have to put the missing piece at its own place.
2. As you reach higher levels, difficulty increases, so does the background scenarios and enemies.
3. Each level has a final boss.
4. At level first you have only attacking way and that is by pressing 'n' key.
5. In the next levels you can use 'f' and 'i'. They are differnet types of attack and does more damage.


Lastly, you may face difficulties while playing this game as its made with a very old technology 'iGraphics'. 
Best of luck nevertheless :)

