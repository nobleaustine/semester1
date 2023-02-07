import pygame

screen_width = 380
screen_height = 500
box_width = 100
gap = 20
box_color = (150,150,150)
reset_box_color = (170,170,170)
screen_color = (200,200,200)
font_color = (50,50,50)
reset_box_coor = (140,450)
win_box_coor = (100,380)
mouse_pos = 0
line_color = (255,0,0)
line_width = 5

pygame.init() 

screen = pygame.display.set_mode((screen_width, screen_height))  
pygame.display.set_caption("Tic Tac Toe") 
box_font = pygame.font.SysFont('freesansbold',128) 
win_font = pygame.font.SysFont('freesansbold',64) 
button_font = pygame.font.SysFont('freesansbold',32) 

surfaces = []
i = 0
while i < 3:
	surfaces.append([])
	j = 0
	while j < 3:
		surfaces[i].append(pygame.Surface((box_width,box_width)))
		j = j + 1
	i = i + 1

win_box = pygame.Surface((180,50))
reset_box = pygame.Surface((110,30))

def start():
	global won, win_text, turn, states
	won = False
	win_text = ""
	turn = 1

	states = []
	i = 0
	while i < 3:
		states.append([])
		j = 0
		while j < 3:
			states[i].append(0)
			j = j + 1
		i = i + 1

def display_box(i,j):
	surfaces[i][j].fill(box_color)
	if states[i][j] == 1:
		surfaces[i][j].blit(box_font.render('X',True,font_color),(20,10))
	if states[i][j] == 2:
		surfaces[i][j].blit(box_font.render('O',True,font_color),(20,10))

def display_screen():
	global turn
	i = 0
	while i < 3:
		j = 0
		while j < 3:
			x = (j+1)*gap+j*box_width
			y = (i+1)*gap+i*box_width
			if mouse_down and not won:
				if surfaces[i][j].get_rect(left=x, top=y).collidepoint(mouse_pos) and states[i][j]==0:
					states[i][j] = turn
					if turn == 1 :
						turn = 2
					else:
						turn = 1
			display_box(i,j)
			screen.blit(surfaces[i][j], (x,y))
			j = j + 1
		i = i + 1

	win_box.fill((255,255,255))
	win_box.blit(win_font.render(win_text, True, (0,0,0)),(15,5))
	screen.blit(win_box,win_box_coor)

	reset_box.fill(reset_box_color)
	reset_box.blit(button_font.render('RESTART', True, (0,0,0)),(5,5))
	screen.blit(reset_box,reset_box_coor)

def check_win(arg):
	i = 0
	while i < 3:
		if states[i][0] == arg and states[i][1] == arg and states[i][2] == arg:
			temp = (i+1)*gap+i*box_width+box_width/2
			pygame.draw.line(screen,line_color,(40,temp),(340,temp),width=line_width)
			return True
		i = i + 1
	i = 0
	while i < 3:
		if states[0][i] == arg and states[1][i] == arg and states[2][i] == arg:
			temp = (i+1)*gap+i*box_width+box_width/2
			pygame.draw.line(screen,line_color,(temp,40),(temp,340),width=line_width)
			return True
		i = i + 1
	if states[0][0] == arg and states[1][1] == arg and states[2][2] == arg:
			pygame.draw.line(screen,line_color,(40,40),(340,340),width=line_width)
			return True
	if states[0][2] == arg and states[1][1] == arg and states[2][0] == arg:
			pygame.draw.line(screen,line_color,(340,40),(40,340),width=line_width)
			return True
	return False

def check_draw():
	draw = True
	i = 0
	while i < 3:
		j = 0
		while j < 3:
			if states[i][j]==0:
				draw = False
			j = j + 1
		i = i + 1
	if draw:
		return True
	return False

start()

while True:

	screen.fill(screen_color)  
	mouse_down = False

	for event in pygame.event.get():
		if event.type == pygame.QUIT: 
			close = True
			pygame.quit()
			break
		if event.type == pygame.MOUSEBUTTONUP:
			mouse_pos = pygame.mouse.get_pos() 
			mouse_down = True

	display_screen()
	if check_draw():
		won = True
		win_text = "DRAW"
	if check_win(1):
		won = True
		win_text = "X WON"
	if check_win(2):
		won = True
		win_text = "O WON"
	if mouse_down:
		if reset_box.get_rect(left=reset_box_coor[0], top=reset_box_coor[1]).collidepoint(mouse_pos):
			start()
	pygame.display.flip()
