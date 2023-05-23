void KillEnemies(Context& ctx) {
	for (auto& obj : ctx.current_scene) {
		if (obj.enemy.enabled) {
			for (auto& bullet : ctx.current_scene) {
				if (bullet.bullet.enabled) {
					if (CheckCollision(obj, bullet).exists) {
						ApplyOnDeath(ctx, obj);
						Destroy(ctx, obj);
						Destroy(ctx, bullet);
					}
				}
			}
		}
	}
}