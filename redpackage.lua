 init("0", 0);
require "TSLib"

local sz = require("sz")
local cjson = sz.json
local http = sz.i82.http

while (true) do
	

	if isFrontApp("com.tencent.xin") == 0 then
		mSleep(3000);
		runApp("com.tencent.xin");
	end

	--[["1、处理设备lock"]]
	if deviceIsLock()  == 1 then	--判断设备是否锁定
		unlockDevice()--解锁无密码的设备
	end
		
end

