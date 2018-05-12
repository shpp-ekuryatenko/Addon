{
  "targets": [
    {
      "target_name": "myaddon",
      "sources": [ "myaddon.cpp" ],
	  	"include_dirs" : [
			"<!(node -e \"require('nan')\")"
		],
    }
  ]
}
