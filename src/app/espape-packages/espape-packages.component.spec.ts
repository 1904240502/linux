import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EspapePackagesComponent } from './espape-packages.component';

describe('EspapePackagesComponent', () => {
  let component: EspapePackagesComponent;
  let fixture: ComponentFixture<EspapePackagesComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EspapePackagesComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(EspapePackagesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
