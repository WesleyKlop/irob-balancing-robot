bot_width = 20;
bot_height = 1;
bot_depth = 6;

difference() {  
    // Base plate
    cube([bot_width, bot_depth, bot_height]); 
    
    // Extrude 4 holes
    padding = 1;
    hole_radius = .5;
 
    
    translate([padding + hole_radius, padding + hole_radius, 0])
    cylinder(h = bot_height, r=hole_radius);
    
    translate([

}