game_map_raw = {
	width = 4,
	height = 4,
	bits = {
			0, 1, 0, 0,
			0, 1, 0, 1,
			0, 1, 0, 1,
			0, 0, 0, 1,
			}
}

game_map_userdata = create_game_map(game_map_raw)
gps = { x = 0, y = 0}

while true do
	print("Enter Command:")
	cin = io.read()
	if cin == "q" then
		break
	elseif cin == "w" then
		print("Enter X:")
		ix = tonumber(io.read())
		print("Enter Y:")
		iy = tonumber(io.read())
		if_move = astar_algorithm(game_map_userdata, gps, {x = ix, y = iy})
		if if_move then
			print("move to " .. ix .. " " .. iy)
		else
			print("stay")
		end
	end
end