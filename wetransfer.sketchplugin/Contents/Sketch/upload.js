function uploadSelection(context) {
	var scriptPath = context.scriptPath;
	var pluginRoot = [scriptPath stringByDeletingLastPathComponent];

	initFramework(context, "WTSketch");
	WTSketchClient.uploadSelection_pluginRoot(context.document, pluginRoot)
}

function initFramework(context, frameworkName) {
	var scriptPath = context.scriptPath;
	var pluginRoot = [scriptPath stringByDeletingLastPathComponent];

	var mocha = [Mocha sharedRuntime];
	if (NSClassFromString(frameworkName) == null) {
  		if (![mocha loadFrameworkWithName:frameworkName inDirectory:pluginRoot]) {
  		 	log('An error ocurred while loading the ' + frameworkName + ' Framework.');
   	 		return;
 		 }
	}
	log('Loaded ' + frameworkName + ' Framework')
}