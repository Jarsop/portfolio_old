---------------------------------- VAR ----------------------------------

local marqueursRecolte = {
  {name="Plant de cannabis", colour=15, id=140, x=2203.27, y=5578.3, z=53.8204},
  {name="Séchage du cannabis", colour=15, id=140, x=2460.11, y=3782.33, z=41.4795},
  {name="Dealer de weed", colour=15, id=140, x=-1476.62, y=171.913, z=55.8878},
  {name="Mine de cuivre", colour=15, id=85, x=2647.44, y=2808.47, z=34.0299},
  {name="Fonderie", colour=15, id=85, x=1038.43, y=2261.32, z=43.7274},
  {name="Revente de cuivre", colour=15, id=85, x=172.353, y=2279.51, z=92.6733},
  {name="Vignes", colour=15, id=93, x=-1767.95, y=2201.6, z=102.744},
  {name="Distillerie", colour=15, id=93, x=840.893, y=-1952.84, z=28.8353},
  {name="Revente de l'alcool", colour=15, id=93, x=466.075, y=-1847.81, z=27.8526},
}

local changeYourJob = {
  {name="Pole Emploi", colour=15, id=351, x=-266.94, y=-960.744, z=31.2231},
  {name="Plant de cannabis", colour=15, id=140, x=2203.27, y=5578.3, z=53.8204},
  {name="Séchage du cannabis", colour=15, id=140, x=2460.11, y=3782.33, z=41.4795},
  {name="Dealer de weed", colour=15, id=140, x=-1476.62, y=171.913, z=55.8878},
  {name="Mine de cuivre", colour=15, id=85, x=2647.44, y=2808.47, z=34.0299},
  {name="Fonderie", colour=15, id=85, x=1038.43, y=2261.32, z=43.7274},
  {name="Revente de cuivre", colour=15, id=85, x=172.353, y=2279.51, z=92.6733},
  {name="Vignes", colour=15, id=93, x=-1767.95, y=2201.6, z=102.744},
  {name="Distillerie", colour=15, id=93, x=840.893, y=-1952.84, z=28.8353},
  {name="Revente de l'alcool", colour=15, id=93, x=466.075, y=-1847.81, z=27.8526},
}

local jobs = {
	{name="Policier", id=2},
	{name="Pompier", id=3},
	{name="Mineur", id=4},
	{name="Chauffeur de taxi", id=5},
	{name="Vigneron", id=6},
}

---------------------------------- FUNCTIONS ----------------------------------

function drawTxt(text,font,centre,x,y,scale,r,g,b,a)
  SetTextFont(font)
  SetTextProportional(0)
  SetTextScale(scale, scale)
  SetTextColour(r, g, b, a)
  SetTextDropShadow(0, 0, 0, 0,255)
  SetTextEdge(1, 0, 0, 0, 255)
  SetTextDropShadow()
  SetTextOutline()
  SetTextCentre(centre)
  SetTextEntry("STRING")
  SetBlipScale(blip, 2.0)
  AddTextComponentString(text)
  DrawText(x , y)
end

function IsNearJobs()
  local ply = GetPlayerPed(-1)
  local plyCoords = GetEntityCoords(ply, 0)
  for _, item in pairs(changeYourJob) do
    local distance = GetDistanceBetweenCoords(item.x, item.y, item.z,  plyCoords["x"], plyCoords["y"], plyCoords["z"], true)
    if(distance <= 10) then
      return true
    end
  end
end

function menuJobs()
  MenuTitle = "Jobs"
  ClearMenu()
  for _, item in pairs(jobs) do
    local nameJob = item.name
    local idJob = item.id
    Menu.addButton(nameJob,"changeJob",idJob)
  end
end

function changeJob(id)
  TriggerServerEvent("jobssystem:jobs", id)
end

---------------------------------- CITIZEN ----------------------------------

Citizen.CreateThread(function()
    for _, item in pairs(marqueursRecolte) do
      item.blip = AddBlipForCoord(item.x, item.y, item.z)
      SetBlipSprite(item.blip, item.id)
      SetBlipAsShortRange(item.blip, true)
      BeginTextCommandSetBlipName("STRING")
      AddTextComponentString(item.name)
      EndTextCommandSetBlipName(item.blip)
    end
end)

Citizen.CreateThread(function()
    for _, item in pairs(changeYourJob) do
      item.blip = AddBlipForCoord(item.x, item.y, item.z)
      SetBlipSprite(item.blip, item.id)
      SetBlipAsShortRange(item.blip, true)
      BeginTextCommandSetBlipName("STRING")
      AddTextComponentString(item.name)
      EndTextCommandSetBlipName(item.blip)
    end
end)

Citizen.CreateThread(function()
  while true do
    Citizen.Wait(0)
    if (IsNearJobs() == true) then
      drawTxt('Appuyer sur ~g~H~s~ pour accéder au menu des métiers',0,1,0.5,0.8,0.6,255,255,255,255)
    if (IsControlJustPressed(1,Keys["H"]) and IsNearJobs() == true) then
      menuJobs()
      Menu.hidden = not Menu.hidden 
    end
  end
    Menu.renderGUI()
  end
end)
