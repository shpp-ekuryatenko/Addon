{
  "targets": [
        {
        "target_name": "my_addon",
        "sources": [ "rainfall_node.cpp",
		],
        "cflags!": [ "-fno-exceptions" ],
        "cflags": [ "-std=c++11" ],
        "cflags_cc!": [ "-fno-exceptions" ],
		#"include_dirs" : [
        #    "<!(node -e \"require('nan')\")"
        #  ],
		"conditions": [
          ["OS=='win'", {
          	"msvs_settings": {
          		"VCCLCompilerTool": {
            	'StringPooling': 'true', # pool string literals
            	'DebugInformationFormat': 3, # Generate a PDB
            	'WarningLevel': 3,
            	'BufferSecurityCheck': 'true',
            	'ExceptionHandling': 1, # /EHsc
            	'SuppressStartupBanner': 'true',
            	'WarnAsError': 'false',
				'RuntimeTypeInfo': 'true'
         		}
        	},
          "include_dirs": [
		    "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/include",
            "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/include/QtCore",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/include/QtWidgets",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/include/QtGui",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/include/QtSvg",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/include/QtANGLE/GLES2",
			"C:/T1/PROJECT/NodeQt/build/Release"
			
          ],
          "libraries": [
            "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Core.lib",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Widgetsd.lib",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Gui.lib",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Svg.lib",
			"C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Svg.lib",
          ],
		  "link_settings": {
              "libraries": [
                   "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Core.lib",
				   "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Widgetsd.lib",
				   "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Gui.lib",
				   "C:/Qt/Qt5.9.1/5.9.1/msvc2015_64/lib/Qt5Svg.lib",
              ]
           }
         }]
        ]
		}
	]
}




